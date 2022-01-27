//
// Created by rombus on 1/26/22.
//

#include "AudioSystem.hpp"
#include "../Utils.h"

#include <iostream>
#include <utility>
#include <sstream>
#include <string>

using namespace fls;

AudioSystem::AudioSystem(std::shared_ptr<AudioSystemSettings> systemSettings) : m_systemSettings(
        std::move(systemSettings)) {
    init(); // TODO: This should probably be in the Workspace, but RAII amirite?
}

void AudioSystem::setSystemSettings(std::shared_ptr<AudioSystemSettings> systemSettings) {
    m_systemSettings = std::move(systemSettings);
}

const std::shared_ptr<AudioSystemSettings> &AudioSystem::getSystemSettings() const {
    return m_systemSettings;
}

void AudioSystem::init() {
    int paInitResult = Pa_Initialize();
    if (paInitResult != paNoError) {
        throw AudioSystemInitException(paInitResult);
    }
    m_initialized = true;
}

void AudioSystem::start() {
    // TODO: Don't use defaults later on
    m_inputDeviceIndex = std::make_unique<PaDeviceIndex>(Pa_GetDefaultInputDevice());
    m_outputDeviceIndex = std::make_unique<PaDeviceIndex>(Pa_GetDefaultOutputDevice());

    m_inputStreamParameters = std::make_unique<PaStreamParameters>();
    m_outputStreamParameters = std::make_unique<PaStreamParameters>();

    m_inputStreamParameters->device = *m_inputDeviceIndex;
    m_outputStreamParameters->device = *m_outputDeviceIndex;

    if(m_inputStreamParameters->device == paNoDevice) {
        std::cerr << "WARNING: No input device found\n";
    }
    if(m_outputStreamParameters->device == paNoDevice) {
        std::cerr << "WARNING: No output device found\n";
    }

    m_inputDeviceInfo = std::make_unique<PaDeviceInfo>(*Pa_GetDeviceInfo(*m_inputDeviceIndex)); // TODO: This could be a memory leak?
    m_outputDeviceInfo = std::make_unique<PaDeviceInfo>(*Pa_GetDeviceInfo(*m_outputDeviceIndex)); // TODO: This could be a memory leak?

    if(m_inputDeviceInfo) {
        std::cout << "Input device name: '" << m_inputDeviceInfo->name << "'\n";
    } else {
        std::cout << "No input device\n";
    }
    if(m_outputDeviceInfo) {
        std::cout << "Output device name: '" << m_outputDeviceInfo->name << "'\n";
    } else {
        std::cout << "No output device\n";
    }

    m_inputStreamParameters->channelCount = (int) m_systemSettings->getNumInputChannels(); // Change this to a regular int, not unsigned
    m_inputStreamParameters->sampleFormat = paFloat32;
    m_inputStreamParameters->suggestedLatency = m_inputDeviceInfo->defaultLowInputLatency;
    m_inputStreamParameters->hostApiSpecificStreamInfo = nullptr;

    m_outputStreamParameters->channelCount = (int) m_systemSettings->getNumOutputChannels(); // Change this to a regular int, not unsigned
    m_outputStreamParameters->sampleFormat = paFloat32;
    m_outputStreamParameters->suggestedLatency = m_outputDeviceInfo->defaultLowInputLatency;
    m_outputStreamParameters->hostApiSpecificStreamInfo = nullptr;

    m_stream = std::make_unique<PaStream *>();

    PaError error = Pa_OpenStream(
        &*m_stream,
        m_inputStreamParameters.get(),
        m_outputStreamParameters.get(),
        m_systemSettings->getSampleRate(),
        m_systemSettings->getBufferSize(),
        paNoFlag,
        nullptr,
        this
    );

    if(error != paNoError) {
        throw AudioSystemInitException(error);
    }

    m_started = true;
}

AudioSystem::~AudioSystem() {
    if(m_initialized) {
        Pa_Terminate();
    }
    if(m_started) {
        Pa_CloseStream(*m_stream);
    }
}

AudioSystemInitException::AudioSystemInitException(int errorNumber) : m_errorNumber(errorNumber) {}

const char *AudioSystemInitException::what() const noexcept {
    std::stringstream msg;
    msg << "An error occurred while using the portaudio stream\n";
    msg << "Error number: " << m_errorNumber << "\n";
    msg << "Error message: " << Pa_GetErrorText(m_errorNumber);
    return utils::to_cstr(msg.str());
}

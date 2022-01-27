//
// Created by rombus on 1/26/22.
//

#include "AudioSystem.hpp"

#include <iostream>
#include <utility>
#include <sstream>
#include <string>

AudioSystem::AudioSystem(std::shared_ptr<AudioSystemSettings> systemSettings) : m_systemSettings(
        std::move(systemSettings)) {}

void AudioSystem::setSystemSettings(std::shared_ptr<AudioSystemSettings> systemSettings) {
    m_systemSettings = std::move(systemSettings);
}

const std::shared_ptr<AudioSystemSettings> &AudioSystem::getSystemSettings() const {
    return m_systemSettings;
}

int AudioSystem::init() {
    int paInitResult = Pa_Initialize();
    if (paInitResult != paNoError) {
        throw AudioSystemInitException(paInitResult);
    }
    initialized = true;
    return paNoError;
}

AudioSystem::~AudioSystem() {
    if(initialized) {
        Pa_Terminate();
    }
}

AudioSystemInitException::AudioSystemInitException(int errorNumber) : m_errorNumber(errorNumber) {}

const char *AudioSystemInitException::what() const noexcept {
    std::stringstream msg;
    msg << "An error occurred while using the portaudio stream\n";
    msg << "Error number: " << m_errorNumber << "\n";
    msg << "Error message: " << Pa_GetErrorText(m_errorNumber);
    return std::move(msg.str()).c_str(); // TODO: Make this a helper
}

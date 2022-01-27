//
// Created by rombus on 1/26/22.
//

#include "AudioSystemSettings.hpp"

using namespace fls;

AudioSystemSettings::AudioSystemSettings(double sampleRate, unsigned long bufferSize, unsigned int numInputChannels, unsigned int numOutputChannels)
        : m_sampleRate(sampleRate),
          m_bufferSize(bufferSize),
          m_numInputChannels(numInputChannels),
          m_numOutputChannels(numOutputChannels){}

void AudioSystemSettings::setSampleRate(double sampleRate) {
    m_sampleRate = sampleRate;
}

double AudioSystemSettings::getSampleRate() const {
    return m_sampleRate;
}

void AudioSystemSettings::setBufferSize(unsigned long bufferSize) {
    m_bufferSize = bufferSize;
}

unsigned long AudioSystemSettings::getBufferSize() const {
    return m_bufferSize;
}

unsigned int AudioSystemSettings::getNumInputChannels() const {
    return m_numInputChannels;
}

void AudioSystemSettings::setNumInputChannels(unsigned int mNumInputChannels) {
    m_numInputChannels = mNumInputChannels;
}

unsigned int AudioSystemSettings::getNumOutputChannels() const {
    return m_numOutputChannels;
}

void AudioSystemSettings::setNumOutputChannels(unsigned int mNumOutputChannels) {
    m_numOutputChannels = mNumOutputChannels;
}


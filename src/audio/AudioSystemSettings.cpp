//
// Created by rombus on 1/26/22.
//

#include "AudioSystemSettings.hpp"

unsigned int AudioSystemSettings::getNumChannels() const {
    return m_numChannels;
}

unsigned long AudioSystemSettings::getBufferSize() const {
    return m_bufferSize;
}

double AudioSystemSettings::getSampleRate() const {
    return m_sampleRate;
}

AudioSystemSettings::AudioSystemSettings(double sampleRate, unsigned long bufferSize, unsigned int numChannels)
        : m_sampleRate(sampleRate),
          m_bufferSize(bufferSize),
          m_numChannels(numChannels) {}

void AudioSystemSettings::setSampleRate(double sampleRate) {
    m_sampleRate = sampleRate;
}

void AudioSystemSettings::setBufferSize(unsigned long bufferSize) {
    m_bufferSize = bufferSize;
}

void AudioSystemSettings::setNumChannels(unsigned int numChannels) {
    m_numChannels = numChannels;
}

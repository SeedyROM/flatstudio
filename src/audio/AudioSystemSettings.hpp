//
// Created by rombus on 1/26/22.
//

#pragma once

struct AudioSystemSettings {
    AudioSystemSettings(
            double sampleRate,
            unsigned long bufferSize,
            unsigned int numChannels
    );

    [[nodiscard]] double getSampleRate() const;

    [[nodiscard]] unsigned long getBufferSize() const;

    [[nodiscard]] unsigned int getNumChannels() const;

    void setSampleRate(double sampleRate);

    void setBufferSize(unsigned long bufferSize);

    void setNumChannels(unsigned int numChannels);

private:
    double m_sampleRate;
    unsigned long m_bufferSize;
    unsigned int m_numChannels;
};

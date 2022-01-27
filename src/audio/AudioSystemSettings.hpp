//
// Created by rombus on 1/26/22.
//

#pragma once

namespace fls {
    struct AudioSystemSettings {
        AudioSystemSettings(
                double sampleRate,
                unsigned long bufferSize,
                unsigned int numInputChannels,
                unsigned int numOutputChannels
        );

        [[nodiscard]] double getSampleRate() const;
        void setSampleRate(double sampleRate);

        [[nodiscard]] unsigned long getBufferSize() const;
        void setBufferSize(unsigned long bufferSize);

        [[nodiscard]] unsigned int getNumInputChannels() const;

        void setNumInputChannels(unsigned int mNumInputChannels);

        [[nodiscard]] unsigned int getNumOutputChannels() const;

        void setNumOutputChannels(unsigned int mNumOutputChannels);

    private:
        double m_sampleRate;
        unsigned long m_bufferSize;
        unsigned int m_numInputChannels;
        unsigned int m_numOutputChannels;
    };
}


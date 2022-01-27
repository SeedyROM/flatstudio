//
// Created by rombus on 1/27/22.
//

#pragma once

#include <vector>
#include <portaudio.h>

#include "Channel.hpp"

namespace fls {
    struct Mixer {
        //
        // IDEA: How the hell do I do this efficiently?
        // EXAMPLE MAYBE?: https://docs.juce.com/master/group__juce__audio__basics-sources.html
        //
        void audioCallback(const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags);

    private:
        std::vector<Channel> m_channels;
    };
}





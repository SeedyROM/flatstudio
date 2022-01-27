//
// Created by rombus on 1/27/22.
//

#include "Mixer.hpp"

using namespace fls;

void Mixer::audioCallback(
    const void *inputBuffer,
    void *outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo *timeInfo,
    PaStreamCallbackFlags statusFlags
) {
    /*
     * Pseudo-code
     *
     * use a circular running buffer
     *
     * for each channel
     * -> get the buffer at the current frame
     * -> add each sample to running buffer / numChannels in mixer
     */
    // TODO: How the fuck do I do that good?
}

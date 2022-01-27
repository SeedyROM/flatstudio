//
// Created by rombus on 1/27/22.
//

#pragma once

namespace fls {
    enum struct ChannelType {
        Mono,
        Stereo
        // Let's just stop here for now, no 5.1 no M/S
    };

    struct Channel {
        Channel();

        explicit Channel(ChannelType type);

        Channel(ChannelType type, float inputGain, bool phase, float pan, float volume);

        // TODO: Impl audio callback
        void audioCallback(...) {}

    protected:
        ChannelType m_type;
        float m_inputGain;
        bool m_phase;
        // std::vector<Insert> inserts;
        float m_pan;
        float m_volume;
    };
}


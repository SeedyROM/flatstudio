//
// Created by rombus on 1/26/22.
//

#pragma once

#include "../audio/AudioSystemSettings.hpp"
#include "../audio/AudioSystem.hpp"

namespace fls {
    struct Workspace {
        explicit Workspace(AudioSystemSettings audioSystemSettings);

        void open();
    private:
        std::shared_ptr<AudioSystemSettings> m_audioSystemSettings;
        std::unique_ptr<AudioSystem> m_audioSystem;
    };
}






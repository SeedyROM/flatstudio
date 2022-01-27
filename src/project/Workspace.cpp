//
// Created by rombus on 1/26/22.
//

#include "Workspace.hpp"

Workspace::Workspace(
        AudioSystemSettings audioSystemSettings
) {
    m_audioSystemSettings = std::make_shared<AudioSystemSettings>(audioSystemSettings);
    m_audioSystem = std::make_unique<AudioSystem>(m_audioSystemSettings);
}

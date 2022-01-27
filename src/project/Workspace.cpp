//
// Created by rombus on 1/26/22.
//

#include "Workspace.hpp"

using namespace fls;

Workspace::Workspace(
        AudioSystemSettings audioSystemSettings
) {
    m_audioSystemSettings = std::make_shared<AudioSystemSettings>(audioSystemSettings);
    m_audioSystem = std::make_unique<AudioSystem>(m_audioSystemSettings);
}

void Workspace::open() {
    m_audioSystem->start();
}

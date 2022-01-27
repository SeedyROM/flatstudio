//
// Created by rombus on 1/26/22.
//

#pragma once

#include <memory>
#include <portaudio.h>

#include "AudioSystemSettings.hpp"

struct AudioSystemInitException : std::exception {
    explicit AudioSystemInitException(int errorNumber);

    [[nodiscard]] const char *what() const noexcept override;

private:
    int m_errorNumber;
};

struct AudioSystem {
    explicit AudioSystem(std::shared_ptr<AudioSystemSettings> systemSettings);

    ~AudioSystem();

    [[nodiscard]] const std::shared_ptr<AudioSystemSettings> &getSystemSettings() const;

    void setSystemSettings(std::shared_ptr<AudioSystemSettings> systemSettings);

    int init();

private:
    std::shared_ptr<AudioSystemSettings> m_systemSettings;
    bool initialized = false;
};


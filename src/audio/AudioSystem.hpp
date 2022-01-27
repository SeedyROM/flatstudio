//
// Created by rombus on 1/26/22.
//

#pragma once

#include <memory>
#include <portaudio.h>

#include "AudioSystemSettings.hpp"

namespace fls {

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

        void init();

        void start();

    private:
        bool m_initialized = false;
        bool m_started = false;

        std::shared_ptr<AudioSystemSettings> m_systemSettings;
        std::unique_ptr<PaDeviceIndex> m_inputDeviceIndex;
        std::unique_ptr<PaDeviceIndex> m_outputDeviceIndex;
        std::unique_ptr<PaDeviceInfo> m_inputDeviceInfo;
        std::unique_ptr<PaDeviceInfo> m_outputDeviceInfo;
        std::unique_ptr<PaStreamParameters> m_inputStreamParameters;
        std::unique_ptr<PaStreamParameters> m_outputStreamParameters;
        std::unique_ptr<PaStream *> m_stream;
    };
}
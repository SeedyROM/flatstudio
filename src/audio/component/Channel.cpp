//
// Created by rombus on 1/27/22.
//

#include "Channel.hpp"

using namespace fls;

Channel::Channel() : Channel(ChannelType::Mono) {}

Channel::Channel(ChannelType type) : m_type(type), m_phase(false), m_inputGain(1), m_pan(0), m_volume(1) {}

Channel::Channel(
        ChannelType type,
        float inputGain,
        bool phase,
        float pan,
        float volume
) :
        m_type(type),
        m_inputGain(inputGain),
        m_phase(phase),
        m_pan(pan),
        m_volume(volume) {}

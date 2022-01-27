cmake_minimum_required(VERSION 3.21)
project(flatstudio)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -Iportaudio)

set(
        SOURCES

        src/Utils.h
        src/audio/AudioSystem.cpp src/audio/AudioSystem.hpp
        src/audio/AudioSystemSettings.cpp src/audio/AudioSystemSettings.hpp
        src/project/Workspace.cpp src/project/Workspace.hpp
        src/audio/component/Mixer.cpp src/audio/component/Mixer.hpp
        src/audio/component/Channel.cpp src/audio/component/Channel.hpp
)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} portaudio)
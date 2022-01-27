cmake_minimum_required(VERSION 3.21)
project(flatstudio)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -Iportaudio)

set(
        SOURCES

        src/main.cpp

        src/audio/AudioSystem.cpp src/audio/AudioSystem.hpp
        src/audio/AudioSystemSettings.cpp src/audio/AudioSystemSettings.hpp
        src/project/Workspace.cpp src/project/Workspace.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} portaudio)
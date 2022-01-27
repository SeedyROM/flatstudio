#include <iostream>

#include "project/Workspace.hpp"

int main() {
    AudioSystemSettings settings(44100, 512, 2);
    Workspace workspace(settings);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
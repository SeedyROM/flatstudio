#include <iostream>

#include "project/Workspace.hpp"

int main() {
    try {
        fls::AudioSystemSettings settings(44100, 512, 1, 2);
        fls::Workspace workspace(settings);

        workspace.open();
    } catch(fls::AudioSystemInitException &e) {
        std::cerr << "Failed to create workspace" << "\n";
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
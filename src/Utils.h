//
// Created by rombus on 1/26/22.
//

#pragma once

#include <string>

namespace utils {
    const char *to_cstr(std::string &&s) {
        static thread_local std::string str;
        str = std::move(s);
        return str.c_str();
    }
}
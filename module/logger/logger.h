#pragma once

#include <cstdarg>
#include <cstdio>
#include <fstream>
#include <iostream>

class _logger {
private:
    static constexpr char filename[] = "module.log";
    static _logger singleton;
    std::FILE* file = nullptr;

    _logger();
    ~_logger();

public:
    static _logger& getSingleton();
    void log(const char* format, ...);
};

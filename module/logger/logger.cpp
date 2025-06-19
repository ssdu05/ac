
#include "logger.h"

_logger _logger::singleton;

_logger::_logger()
{
    fopen_s(&file, filename, "w");
}

_logger::~_logger()
{
    if (file)
        std::fclose(file);
}

_logger&
_logger::getSingleton()
{
    return singleton;
}

void
_logger::log(const char* format, ...)
{
    if (!file)
        return;

    va_list args;
    va_start(args, format);
    std::vfprintf(file, format, args);
    std::fflush(file);
    vprintf(format , args);
    va_end(args);
}

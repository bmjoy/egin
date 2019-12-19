#include <iostream>
#include <stdarg.h>
#include <vector>
#include "Logger.hpp"

using namespace core;

Logger core::logger;

std::string format(const char *fmt, va_list args)
{
    std::vector<char> v(1024);
    while (true)
    {
        va_list args2;
        va_copy(args2, args);
        int res = vsnprintf(v.data(), v.size(), fmt, args2);
        if ((res >= 0) && (res < static_cast<int>(v.size())))
        {
            va_end(args);
            va_end(args2);
            return std::string(v.data());
        }
        size_t size;
        if (res < 0)
            size = v.size() * 2;
        else
            size = static_cast<size_t>(res) + 1;
        v.clear();
        v.resize(size);
        va_end(args2);
    }
}

Logger::Logger() {

}

void Logger::log(const char* message, ...) {
  va_list args;
  va_start(args, message);
  std::cout << "[LOG] " << format(message, args) << std::endl;
}

Logger::~Logger() {

}
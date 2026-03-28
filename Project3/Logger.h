#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger {
public:
    static void log(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);
    static void success(const std::string& message);
};

#endif
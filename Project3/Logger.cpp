#include "Logger.h"
#include <iostream>

void Logger::log(const std::string& message) {
    std::cout << "[LOG] " << message << "\n";
}

void Logger::warning(const std::string& message) {
    std::cout << "\033[33m[WARNING] " << message << "\033[0m\n";
}

void Logger::error(const std::string& message) {
    std::cout << "\033[31;1m[ERROR] " << message << "\033[0m\n";
}

void Logger::success(const std::string& message) {
    std::cout << "\033[32m[SUCCESS] " << message << "\033[0m\n";
}
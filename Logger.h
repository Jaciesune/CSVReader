#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

class Logger {
private:
    std::ofstream logFile;
    std::ofstream errorLogFile;

public:
    Logger();
    ~Logger();

    void log(const std::string& message);
    void logError(const std::string& errorMessage);
};

#endif // LOGGER_H
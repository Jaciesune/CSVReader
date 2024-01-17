#include "Logger.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <stdexcept> // std::runtime_error

Logger::Logger() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* localTime = std::localtime(&now);

    std::stringstream logFileName;
    logFileName << "log_data_" << std::put_time(localTime, "%Y-%m-%d_%H-%M-%S") << ".txt";
    logFile.open(logFileName.str(), std::ios::app);

    if (!logFile.is_open()) {
        throw std::runtime_error("Error: Log file could not be opened.");
    }

    std::stringstream errorLogFileName;
    errorLogFileName << "log_error_" << std::put_time(localTime, "%Y-%m-%d_%H-%M-%S") << ".txt";
    errorLogFile.open(errorLogFileName.str(), std::ios::app);

    if (!errorLogFile.is_open()) {
        // Close the logFile if errorLogFile failed to open
        logFile.close();
        throw std::runtime_error("Error: Error log file could not be opened.");
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }

    if (errorLogFile.is_open()) {
        errorLogFile.close();
    }
}

void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    } else {
        std::cerr << "Error: Log file not open." << std::endl;
    }
}

void Logger::logError(const std::string& errorMessage) {
    if (errorLogFile.is_open()) {
        errorLogFile << errorMessage << std::endl;
    } else {
        std::cerr << "Error: Error log file not open." << std::endl;
    }
}
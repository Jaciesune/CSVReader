#pragma once
#include <string>
#include <fstream>

class Logger {
private:
    std::ofstream logFile;

public:
    Logger(const std::string& filename);

    void log(const std::string& message);
    // inne metody, jeśli potrzebne
};

#pragma once
#include <string>
#include "PointData.h"

class CSVParser {
public:
    static PointData* parseLine(const std::string& line);
    // inne metody, jeśli potrzebne
};

#pragma once

#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include "PointData.h"
#include <string>
#include <vector>
#include <memory> // Include the necessary header for std::unique_ptr


class CSVParser {
public:
    static std::vector<std::unique_ptr<PointData>> parseLine(const std::string& line);
};

#endif // CSV_PARSER_H
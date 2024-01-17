#pragma once
#ifndef DATA_ANALYZER_H
#define DATA_ANALYZER_H

#include "TreeData.h"
#include <string>
#include <vector>
#include <memory>


class DataAnalyzer {
private:
    TreeData treeData;

public:
    void analyzeAutokonsumpcja(const std::string& startTime, const std::string& endTime);
    double calculateSumAutokonsumpcja(const std::string& startTime, const std::string& endTime);
    void processData(const std::vector<std::unique_ptr<PointData>>& data);
};
#endif // DATA_ANALYZER_H
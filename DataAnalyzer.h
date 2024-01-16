#pragma once
#include <string>
#include "TreeData.h"

class DataAnalyzer {
private:
    TreeData treeData;

public:
    void analyzeAutokonsumpcja(const std::string& startTime, const std::string& endTime);
    void analyzeEksport(const std::string& startTime, const std::string& endTime);
    // inne metody, jeśli potrzebne
};

#pragma once

#ifndef TREE_DATA_H
#define TREE_DATA_H

#include <map>
#include <vector>
#include "PointData.h"

class TreeData {
private:
    struct TreeNode {
        std::map<int, TreeNode> months;
        std::map<int, TreeNode> days;
        std::vector<std::vector<PointData*>> quarters;  
        std::vector<PointData*> points;
    };

    TreeNode root;

    void traverseTreeForTimeRange(TreeNode& current, int startYear, int startMonth, int startDay, int startHour,
                                   int endYear, int endMonth, int endDay, int endHour, std::vector<PointData*>& result);

public:
    TreeData();

    void insertPoint(PointData* point);
    std::vector<PointData*> getPointsWithinTimeRange(const std::string& startTime, const std::string& endTime);
    
};

#endif // TREE_DATA_H

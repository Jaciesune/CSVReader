#pragma once

#include <map>
#include <vector>
#include "PointData.cpp"

class TreeData {
private:
    struct TreeNode {
        std::map<int, TreeNode> months;
        std::map<int, TreeNode> days;
        std::vector<std::vector<PointData*>> quarters;  
    };

    TreeNode root;

public:
    TreeData();

    void insertPoint(PointData* point);
    
};

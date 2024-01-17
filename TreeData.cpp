#include "TreeData.h"
#include <iostream>
#include <sstream> // For std::istringstream

TreeData::TreeData() {
    // Konstruktor
}

void TreeData::insertPoint(PointData* point) {
    // Wstawienie punktu do drzewa
    TreeNode* current = &root;

    // Rozbicie daty na części: rok, miesiąc, dzień, godzinę
    int year, month, day, hour;

    // Use std::istringstream for parsing
    std::istringstream ss(point->getTime());
    char dash; // To capture '-'
    char colon; // To capture ':'

    if (!(ss >> year >> dash >> month >> dash >> day >> hour >> colon)) {
        // Handle parsing error
        std::cerr << "Error: Unable to parse time for point: " << point->getTime() << std::endl;
        return; // Skip this point if unable to parse time
    }

    // Wstawianie do drzewa
    current = &(current->months[year]);
    current = &(current->months[month]);
    current = &(current->days[day]);

    // Sprawdzenie, czy quarters są już zainicjalizowane
    int quarter = (hour / 6) + 1;
    if (current->quarters.size() < 4) {
        // Inicjalizacja quarters
        current->quarters.resize(4);
    }

    // Wstawienie punktu do quarters
    std::vector<PointData*>* currentQuarters = &(current->quarters[quarter]);
    currentQuarters->push_back(point);

    // Testowy wypis dla potwierdzenia poprawności wstawiania
    std::cout << "Inserted point: " << point->getTime() << std::endl;
}

std::vector<PointData*> TreeData::getPointsWithinTimeRange(const std::string& startTime, const std::string& endTime) {
    std::vector<PointData*> result;

    // Convert start and end time to integers for comparison
    int startYear, startMonth, startDay, startHour;
    int endYear, endMonth, endDay, endHour;
    sscanf(startTime.c_str(), "%d-%d-%d %d:%*d", &startYear, &startMonth, &startDay, &startHour);
    sscanf(endTime.c_str(), "%d-%d-%d %d:%*d", &endYear, &endMonth, &endDay, &endHour);

    // Traverse the tree to find points within the specified time range
    traverseTreeForTimeRange(root, startYear, startMonth, startDay, startHour, endYear, endMonth, endDay, endHour, result);

    return result;
}

void TreeData::traverseTreeForTimeRange(TreeData::TreeNode& current, int startYear, int startMonth, int startDay, int startHour,
                                         int endYear, int endMonth, int endDay, int endHour, std::vector<PointData*>& result) {
    // Check if the current node has points within the specified time range
    for (size_t i = 0; i < current.points.size(); ++i) {
        const auto& point = current.points[i];

        // Extract year, month, day, and hour information from the point's time
        int pointYear, pointMonth, pointDay, pointHour;
        sscanf(point->getTime().c_str(), "%d-%d-%d %d:%*d", &pointYear, &pointMonth, &pointDay, &pointHour);

        // Check if the point is within the time range
        if (pointYear > startYear || (pointYear == startYear && pointMonth > startMonth) ||
            (pointYear == startYear && pointMonth == startMonth && pointDay > startDay) ||
            (pointYear == startYear && pointMonth == startMonth && pointDay == startDay && pointHour >= startHour)) {
            
            if (pointYear < endYear || (pointYear == endYear && pointMonth < endMonth) ||
                (pointYear == endYear && pointMonth == endMonth && pointDay < endDay) ||
                (pointYear == endYear && pointMonth == endMonth && pointDay == endDay && pointHour <= endHour)) {
                
                result.push_back(point);
            }
        }
    }

    // Recursively traverse the children
    for (auto it = current.months.begin(); it != current.months.end(); ++it) {
        traverseTreeForTimeRange(it->second, startYear, startMonth, startDay, startHour, endYear, endMonth, endDay, endHour, result);
    }

    for (auto it = current.days.begin(); it != current.days.end(); ++it) {
        traverseTreeForTimeRange(it->second, startYear, startMonth, startDay, startHour, endYear, endMonth, endDay, endHour, result);
    }

    // No need to traverse quarters in this case as we're only interested in points
}
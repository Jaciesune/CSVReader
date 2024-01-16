#include "TreeData.h"
#include <iostream>

TreeData::TreeData() {
    // Konstruktor
}

void TreeData::insertPoint(PointData* point) {
    // Wstawienie punktu do drzewa
    TreeNode* current = &root;

    // Rozbicie daty na części: rok, miesiąc, dzień, godzinę
    int year, month, day, hour;
    sscanf(point->time.c_str(), "%d-%d-%d %d:%*d", &year, &month, &day, &hour);

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

    // Directly assign the vector to current
    current = &(current->quarters[quarter]);

    // Assuming that you have a vector named 'points' in your TreeNode structure
    current->push_back(point);

    // Testowy wypis dla potwierdzenia poprawności wstawiania
    std::cout << "Inserted point: " << point->time << std::endl;
}
// PointData.h
#pragma once
#include <string>

// Struktura reprezentująca pojedynczy punkt danych
struct DataPoint {
    std::string time;
    double autokonsumpcja;
    double eksport;
    double import;
    double pobor;
    double produkcja;
};

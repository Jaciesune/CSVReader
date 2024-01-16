#pragma once
#include <string>

class PointData {
public:
    std::string time;
    double autokonsumpcja;
    double eksport;
    double import;
    double pobor;
    double produkcja;

    PointData(const std::string& time, double autokonsumpcja, double eksport, double import, double pobor, double produkcja);
    // inne metody, jeśli potrzebne
};
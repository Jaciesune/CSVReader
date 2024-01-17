#pragma once

#ifndef POINT_DATA_H
#define POINT_DATA_H

#include <string>

class PointData {
private:
    std::string time;
    double autokonsumpcja;
    double eksport;
    double import;
    double pobor;
    double produkcja;

public:
    PointData(const std::string& time, double autokonsumpcja, double eksport, double import, double pobor, double produkcja);

    // Getter methods
    std::string getTime() const;
    double getAutokonsumpcja() const;
    double getEksport() const;
    double getImport() const;
    double getPobor() const;
    double getProdukcja() const;
};

#endif // POINT_DATA_H
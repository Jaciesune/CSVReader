#include "PointData.h"

PointData::PointData(const std::string& time, double autokonsumpcja, double eksport, double import, double pobor, double produkcja)
    : time(time), autokonsumpcja(autokonsumpcja), eksport(eksport), import(import), pobor(pobor), produkcja(produkcja) {
    // implementacja konstruktora
}

// Implementation of getter methods
std::string PointData::getTime() const {
    return time;
}

double PointData::getAutokonsumpcja() const {
    return autokonsumpcja;
}

double PointData::getEksport() const {
    return eksport;
}

double PointData::getImport() const {
    return import;
}

double PointData::getPobor() const {
    return pobor;
}

double PointData::getProdukcja() const {
    return produkcja;
}
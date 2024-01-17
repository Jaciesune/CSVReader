#include "DataAnalyzer.h"
#include "CSVParser.h"
#include "Logger.h"

double DataAnalyzer::calculateSumAutokonsumpcja(const std::string& startTime, const std::string& endTime) {
    double sum = 0.0;

    // Pobierz punkty z drzewa, które mieszczą się w określonym zakresie czasowym
    std::vector<PointData*> pointsInRange = treeData.getPointsWithinTimeRange(startTime, endTime);

    // Sumuj autokonsumpcję dla każdego punktu w zakresie
    for (const auto& point : pointsInRange) {
        sum += point->getAutokonsumpcja();
    }

    return sum;
}

void DataAnalyzer::analyzeAutokonsumpcja(const std::string& startTime, const std::string& endTime) {
    // Wczytaj dane z pliku CSV i wstaw je do drzewa
    CSVParser csvParser;
    std::vector<std::unique_ptr<PointData>> data = csvParser.parseLine("nazwa_pliku.csv");

    for (auto& point : data) {
        treeData.insertPoint(point.get());
    }

    // Oblicz sumę autokonsumpcji w określonym zakresie czasowym
    double sumAutokonsumpcja = calculateSumAutokonsumpcja(startTime, endTime);

    // Wypisz wynik do logu
    Logger logger;
    logger.log("Suma autokonsumpcji w okresie od " + startTime + " do " + endTime + ": " + std::to_string(sumAutokonsumpcja));
}

void DataAnalyzer::processData(const std::vector<std::unique_ptr<PointData>>& data) {
    for (const auto& point : data) {
        treeData.insertPoint(point.get());
    }
}

#include "CSVParser.h"
#include "DataAnalyzer.h"
#include "Logger.h"
#include <iostream>
#include <memory>
#include <iomanip> // for std::put_time

int main() {
    // Wczytanie pliku CSV
    CSVParser csvParser;
    std::vector<std::unique_ptr<PointData>> data = csvParser.parseLine("./Chart Export.csv");

    // Sprawdzenie, czy wczytanie danych z pliku CSV zakończyło się sukcesem
    if (data.empty()) {
        std::cerr << "Błąd: Wczytywanie danych z pliku CSV nie powiodło się." << std::endl;
        return 1; // Zwrócenie kodu błędu
    }

    // Analiza danych
    DataAnalyzer dataAnalyzer;
    dataAnalyzer.processData(data);

    // Przykład wypisania sumy autokonsumpcji w określonych datach i godzinach
    std::string startTime = "2021-10-03 10:15";
    std::string endTime = "2021-10-03 16:45";

    double consumptionSum = dataAnalyzer.calculateSumAutokonsumpcja(startTime, endTime);

    // Wypisanie podsumowania
    Logger logger;
    logger.log("Suma autokonsumpcji w okresie od " + startTime + " do " + endTime + ": " + std::to_string(consumptionSum));

    return 0;
}

#include "CSVParser.h"
#include "Logger.h"
#include <sstream>

std::vector<std::unique_ptr<PointData>> CSVParser::parseLine(const std::string& line) {
    std::vector<std::unique_ptr<PointData>> result;

    // Użyj strumienia istringstream do podziału linii na pola CSV
    std::istringstream ss(line);
    std::string token;

    // Odczytaj pierwsze pole (czas)
    std::getline(ss, token, ',');

    // Odczytaj pozostałe pola
    try {
        std::getline(ss, token, ',');
        double autokonsumpcja = std::stod(token);

        std::getline(ss, token, ',');
        double eksport = std::stod(token);

        std::getline(ss, token, ',');
        double import = std::stod(token);

        std::getline(ss, token, ',');
        double pobor = std::stod(token);

        std::getline(ss, token, ',');
        double produkcja = std::stod(token);

        // Użyj std::make_unique do utworzenia std::unique_ptr<PointData>
        auto parsedData = std::make_unique<PointData>(token, autokonsumpcja, eksport, import, pobor, produkcja);

        // Umieść obiekt w wektorze
        result.push_back(std::move(parsedData));

        // Loguj do pliku z danymi
        Logger dataLogger;
        dataLogger.log("Przetworzony rekord: " + line);
    } catch (const std::invalid_argument& e) {
        // Loguj do pliku z błędami w przypadku niepoprawnej konwersji
        Logger errorLogger;
        errorLogger.logError("Niepoprawny rekord (błąd konwersji): " + line);
    }

    return result;
}
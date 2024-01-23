//program wyświetla menu i pozwala wybrać opcję
//wywołuje odpowiednią metodę z klasy DataTree
//wyświetla wynik działania metody
//powtarza działanie do momentu wybrania opcji 0
//
// Path: main.cpp
#include "pointData.h"
#include "treeData.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;



// Implementacja metody wczytującej dane z pliku CSV
void DataTree::loadDataFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    // Ustawienie standardowego separatora dziesiętnego na przecinek
    std::locale::global(std::locale("C"));

    std::string line;
    std::getline(file, line); // Pominięcie pierwszej linii opisowej

    while (std::getline(file, line) && !line.empty()) {
        std::istringstream ss(line);
        DataPoint point;

        std::getline(ss, point.time, ',');

        // Pominięcie cudzysłowów dla wartości liczbowych
        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
        ss >> point.autokonsumpcja;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');

        ss.ignore(); // Pominięcie przecinka

        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
        ss >> point.eksport;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');

        ss.ignore(); // Pominięcie przecinka

        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
        ss >> point.import;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');

        ss.ignore(); // Pominięcie przecinka

        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
        ss >> point.pobor;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');

        ss.ignore(); // Pominięcie przecinka

        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
        ss >> point.produkcja;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), '"');

        if (ss.fail()) {
            // Obsługa błędu konwersji
            std::cerr << "Błąd konwersji dla linii: " << line << std::endl;
            continue; // Przejdź do kolejnej iteracji pętli
        }

        data.push_back(point);
        std::cout << "Time: " << point.time << ", Autokonsumpcja: " << point.autokonsumpcja
            << ", Eksport: " << point.eksport << ", Import: " << point.import
            << ", Pobor: " << point.pobor << ", Produkcja: " << point.produkcja << std::endl;
    }

    file.close();
}


// Funkcja pomocnicza do konwersji daty i godziny na znacznik czasu (timestamp)
time_t DataTree::convertToTimestamp(const string& datetime) {
    tm time = {};
    stringstream ss(datetime);
    ss >> get_time(&time, "%d.%m.%Y %H:%M");
    if (ss.fail()) {
        cerr << "Błąd parsowania daty i godziny: " << datetime << endl;
        return -1;  // Zwróć wartość oznaczającą błąd (np. -1)
    }
    return mktime(&time);
}


// Metody opisane w treści zadania

void DataTree::printAutokonsumpcjaSum(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.autokonsumpcja;
        }
    }

    cout << "Suma autokonsumpcji w przedziale czasowym " << start << " - " << end << " wynosi " << sum << endl;
}

void DataTree::printEksportSum(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.eksport;
        }
    }

    cout << "Suma eksportu w przedziale czasowym " << start << " - " << end << " wynosi " << sum << endl;
}

void DataTree::printImportSum(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.import;
        }
    }

    cout << "Suma importu w przedziale czasowym " << start << " - " << end << " wynosi " << sum << endl;
}

void DataTree::printPoborSum(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.pobor;
        }
    }

    cout << "Suma poboru w przedziale czasowym " << start << " - " << end << " wynosi " << sum << endl;
}

void DataTree::printProdukcjaSum(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.produkcja;
        }
    }

    cout << "Suma produkcji w przedziale czasowym " << start << " - " << end << " wynosi " << sum << endl;
}

void DataTree::printAutokonsumpcjaAverage(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    int count = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.autokonsumpcja;
            count++;
        }
    }

    cout << "Srednia autokonsumpcja w przedziale czasowym " << start << " - " << end << " wynosi " << sum / count << endl;
}

void DataTree::printEksportAverage(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    int count = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.eksport;
            count++;
        }
    }

    cout << "Srednia eksportu w przedziale czasowym " << start << " - " << end << " wynosi " << sum / count << endl;
}

void DataTree::printImportAverage(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    int count = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.import;
            count++;
        }
    }

    cout << "Srednia importu w przedziale czasowym " << start << " - " << end << " wynosi " << sum / count << endl;
}

void DataTree::printPoborAverage(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    int count = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.pobor;
            count++;
        }
    }

    cout << "Srednia poboru w przedziale czasowym " << start << " - " << end << " wynosi " << sum / count << endl;
}

void DataTree::printProdukcjaAverage(const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    double sum = 0;
    int count = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp) {
            sum += point.produkcja;
            count++;
        }
    }

    cout << "Srednia produkcji w przedziale czasowym " << start << " - " << end << " wynosi " << sum / count << endl;
}

void DataTree::compareAutokonsumpcja(const string& start1, const string& end1, const string& start2, const string& end2) {
    time_t startTimestamp1 = convertToTimestamp(start1);
    time_t endTimestamp1 = convertToTimestamp(end1);
    time_t startTimestamp2 = convertToTimestamp(start2);
    time_t endTimestamp2 = convertToTimestamp(end2);

    double sum1 = 0;
    int count1 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp1 && pointTimestamp <= endTimestamp1) {
            sum1 += point.autokonsumpcja;
            count1++;
        }
    }

    double sum2 = 0;
    int count2 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp2 && pointTimestamp <= endTimestamp2) {
            sum2 += point.autokonsumpcja;
            count2++;
        }
    }

    cout << "Srednia autokonsumpcja w przedziale czasowym " << start1 << " - " << end1 << " wynosi " << sum1 / count1 << endl;
    cout << "Srednia autokonsumpcja w przedziale czasowym " << start2 << " - " << end2 << " wynosi " << sum2 / count2 << endl;
}

void DataTree::compareEksport(const string& start1, const string& end1, const string& start2, const string& end2) {
    time_t startTimestamp1 = convertToTimestamp(start1);
    time_t endTimestamp1 = convertToTimestamp(end1);
    time_t startTimestamp2 = convertToTimestamp(start2);
    time_t endTimestamp2 = convertToTimestamp(end2);

    double sum1 = 0;
    int count1 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp1 && pointTimestamp <= endTimestamp1) {
            sum1 += point.eksport;
            count1++;
        }
    }

    double sum2 = 0;
    int count2 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp2 && pointTimestamp <= endTimestamp2) {
            sum2 += point.eksport;
            count2++;
        }
    }

    cout << "Srednia eksportu w przedziale czasowym " << start1 << " - " << end1 << " wynosi " << sum1 / count1 << endl;
    cout << "Srednia eksportu w przedziale czasowym " << start2 << " - " << end2 << " wynosi " << sum2 / count2 << endl;
}

void DataTree::compareImport(const string& start1, const string& end1, const string& start2, const string& end2) {
    time_t startTimestamp1 = convertToTimestamp(start1);
    time_t endTimestamp1 = convertToTimestamp(end1);
    time_t startTimestamp2 = convertToTimestamp(start2);
    time_t endTimestamp2 = convertToTimestamp(end2);

    double sum1 = 0;
    int count1 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp1 && pointTimestamp <= endTimestamp1) {
            sum1 += point.import;
            count1++;
        }
    }

    double sum2 = 0;
    int count2 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp2 && pointTimestamp <= endTimestamp2) {
            sum2 += point.import;
            count2++;
        }
    }

    cout << "Srednia importu w przedziale czasowym " << start1 << " - " << end1 << " wynosi " << sum1 / count1 << endl;
    cout << "Srednia importu w przedziale czasowym " << start2 << " - " << end2 << " wynosi " << sum2 / count2 << endl;
}

void DataTree::comparePobor(const string& start1, const string& end1, const string& start2, const string& end2) {
    time_t startTimestamp1 = convertToTimestamp(start1);
    time_t endTimestamp1 = convertToTimestamp(end1);
    time_t startTimestamp2 = convertToTimestamp(start2);
    time_t endTimestamp2 = convertToTimestamp(end2);

    double sum1 = 0;
    int count1 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp1 && pointTimestamp <= endTimestamp1) {
            sum1 += point.pobor;
            count1++;
        }
    }

    double sum2 = 0;
    int count2 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp2 && pointTimestamp <= endTimestamp2) {
            sum2 += point.pobor;
            count2++;
        }
    }

    cout << "Srednia poboru w przedziale czasowym " << start1 << " - " << end1 << " wynosi " << sum1 / count1 << endl;
    cout << "Srednia poboru w przedziale czasowym " << start2 << " - " << end2 << " wynosi " << sum2 / count2 << endl;
}

void DataTree::compareProdukcja(const string& start1, const string& end1, const string& start2, const string& end2) {
    time_t startTimestamp1 = convertToTimestamp(start1);
    time_t endTimestamp1 = convertToTimestamp(end1);
    time_t startTimestamp2 = convertToTimestamp(start2);
    time_t endTimestamp2 = convertToTimestamp(end2);

    double sum1 = 0;
    int count1 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp1 && pointTimestamp <= endTimestamp1) {
            sum1 += point.produkcja;
            count1++;
        }
    }

    double sum2 = 0;
    int count2 = 0;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp2 && pointTimestamp <= endTimestamp2) {
            sum2 += point.produkcja;
            count2++;
        }
    }

    cout << "Srednia produkcji w przedziale czasowym " << start1 << " - " << end1 << " wynosi " << sum1 / count1 << endl;
    cout << "Srednia produkcji w przedziale czasowym " << start2 << " - " << end2 << " wynosi " << sum2 / count2 << endl;
}

void DataTree::searchAndPrint(const double value, const double tolerance, const string& start, const string& end) {
    time_t startTimestamp = convertToTimestamp(start);
    time_t endTimestamp = convertToTimestamp(end);

    cout << "Wartosc " << value << " w przedziale czasowym " << start << " - " << end << " wystepuje w nastepujacych punktach:" << endl;
    for (const auto& point : data) {
        time_t pointTimestamp = convertToTimestamp(point.time);
        if (pointTimestamp >= startTimestamp && pointTimestamp <= endTimestamp && point.autokonsumpcja >= value - tolerance && point.autokonsumpcja <= value + tolerance) {
            cout << point.time << " " << point.autokonsumpcja << endl;
        }
    }
}

void DataTree::saveBinaryFile(const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku " << filename << endl;
        return;
    }

    for (const auto& point : data) {
        file.write(reinterpret_cast<const char*>(&point), sizeof(point));
    }
}

void DataTree::readBinaryFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Nie udało się otworzyć pliku " << filename << std::endl;
        return;
    }

    DataPoint point;
    while (file.read(reinterpret_cast<char*>(&point), sizeof(point))) {
        data.push_back(point);

        std::cout << "Wczytano dane: Time=" << point.time
                  << ", Autokonsumpcja=" << point.autokonsumpcja
                  << ", Eksport=" << point.eksport
                  << ", Import=" << point.import
                  << ", Pobór=" << point.pobor
                  << ", Produkcja=" << point.produkcja << std::endl;
    }

    file.close();
}

// Funkcja pomocnicza do wyświetlania menu

void printMenu() {
    cout << "1. Wczytaj dane z pliku" << endl;
    cout << "2. Suma autokonsumpcji w przedziale czasowym" << endl;
    cout << "3. Suma eksportu w przedziale czasowym" << endl;
    cout << "4. Suma importu w przedziale czasowym" << endl;
    cout << "5. Suma poboru w przedziale czasowym" << endl;
    cout << "6. Suma produkcji w przedziale czasowym" << endl;
    cout << "7. Srednia autokonsumpcja w przedziale czasowym" << endl;
    cout << "8. Srednia eksportu w przedziale czasowym" << endl;
    cout << "9. Srednia importu w przedziale czasowym" << endl;
    cout << "10. Srednia poboru w przedziale czasowym" << endl;
    cout << "11. Srednia produkcji w przedziale czasowym" << endl;
    cout << "12. Porownaj srednia autokonsumpcje w dwoch przedzialach czasowych" << endl;
    cout << "13. Porownaj srednia eksportu w dwoch przedzialach czasowych" << endl;
    cout << "14. Porownaj srednia importu w dwoch przedzialach czasowych" << endl;
    cout << "15. Porownaj srednia poboru w dwoch przedzialach czasowych" << endl;
    cout << "16. Porownaj srednia produkcji w dwoch przedzialach czasowych" << endl;
    cout << "17. Wyszukaj i wyswietl punkty, w ktorych autokonsumpcja jest rowna zadanej wartosci z tolerancja" << endl;
    cout << "18. Zapisz dane do pliku binarnego" << endl;
    cout << "19. Wczytaj dane z pliku binarnego" << endl;
    cout << "0. Wyjscie" << endl;
}

// Główna funkcja programu

int main() {
    DataTree tree;

    int option;
    do {
        printMenu();
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option) {
        case 1: {
            std::string filename;
            std::cout << "Podaj nazwe pliku: ";
            std::getline(std::cin, filename);
            tree.loadDataFromFile(filename);
            break;
        }
        case 2: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printAutokonsumpcjaSum(start, end);
            break;
        }
        case 3: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printEksportSum(start, end);
            break;
        }
        case 4: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printImportSum(start, end);
            break;
        }
        case 5: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printPoborSum(start, end);
            break;
        }
        case 6: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printProdukcjaSum(start, end);
            break;
        }
        case 7: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printAutokonsumpcjaAverage(start, end);
            break;
        }
        case 8: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printEksportAverage(start, end);
            break;
        }
        case 9: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printImportAverage(start, end);
            break;
        }
        case 10: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printPoborAverage(start, end);
            break;
        }
        case 11: {
            string start, end;
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.printProdukcjaAverage(start, end);
            break;
        }
        case 12: {
            string start1, end1, start2, end2;
            cout << "Podaj poczatek pierwszego przedzialu: ";
            getline(cin, start1);
            cout << "Podaj koniec pierwszego przedzialu: ";
            getline(cin, end1);
            cout << "Podaj poczatek drugiego przedzialu: ";
            getline(cin, start2);
            cout << "Podaj koniec drugiego przedzialu: ";
            getline(cin, end2);
            tree.compareAutokonsumpcja(start1, end1, start2, end2);
            break;
        }
        case 13: {
            string start1, end1, start2, end2;
            cout << "Podaj poczatek pierwszego przedzialu: ";
            getline(cin, start1);
            cout << "Podaj koniec pierwszego przedzialu: ";
            getline(cin, end1);
            cout << "Podaj poczatek drugiego przedzialu: ";
            getline(cin, start2);
            cout << "Podaj koniec drugiego przedzialu: ";
            getline(cin, end2);
            tree.compareEksport(start1, end1, start2, end2);
            break;
        }
        case 14: {
            string start1, end1, start2, end2;
            cout << "Podaj poczatek pierwszego przedzialu: ";
            getline(cin, start1);
            cout << "Podaj koniec pierwszego przedzialu: ";
            getline(cin, end1);
            cout << "Podaj poczatek drugiego przedzialu: ";
            getline(cin, start2);
            cout << "Podaj koniec drugiego przedzialu: ";
            getline(cin, end2);
            tree.compareImport(start1, end1, start2, end2);
            break;
        }
        case 15: {
            string start1, end1, start2, end2;
            cout << "Podaj poczatek pierwszego przedzialu: ";
            getline(cin, start1);
            cout << "Podaj koniec pierwszego przedzialu: ";
            getline(cin, end1);
            cout << "Podaj poczatek drugiego przedzialu: ";
            getline(cin, start2);
            cout << "Podaj koniec drugiego przedzialu: ";
            getline(cin, end2);
            tree.comparePobor(start1, end1, start2, end2);
            break;
        }
        case 16: {
            string start1, end1, start2, end2;
            cout << "Podaj poczatek pierwszego przedzialu: ";
            getline(cin, start1);
            cout << "Podaj koniec pierwszego przedzialu: ";
            getline(cin, end1);
            cout << "Podaj poczatek drugiego przedzialu: ";
            getline(cin, start2);
            cout << "Podaj koniec drugiego przedzialu: ";
            getline(cin, end2);
            tree.compareProdukcja(start1, end1, start2, end2);
            break;
        }
        case 17: {
            double value, tolerance;
            string start, end;
            cout << "Podaj wartosc: ";
            cin >> value;
            cout << "Podaj tolerancje: ";
            cin >> tolerance;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podaj poczatek przedzialu: ";
            getline(cin, start);
            cout << "Podaj koniec przedzialu: ";
            getline(cin, end);
            tree.searchAndPrint(value, tolerance, start, end);
            break;
        }
        case 18: {
            string filename;
            cout << "Podaj nazwe pliku: ";
            getline(cin, filename);
            tree.saveBinaryFile(filename);
            break;
        }
        case 19: {
            string filename;
            cout << "Podaj nazwe pliku: ";
            getline(cin, filename);
            tree.readBinaryFile(filename);
            break;
        }
        case 0:
            break;
        default:
            cout << "Nieznana opcja" << endl;
        }
    } while (option != 0);

    return 0;
}


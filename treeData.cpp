// Funkcja pomocnicza do wczytywania danych z pliku

#include "treeData.h"

void DataTree::loadDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Pomijamy pierwszy wiersz z nagłówkami kolumn

    while (getline(file, line)) {
        stringstream ss(line);
        string datetime;
        double autokonsumpcja, eksport, import, pobor, produkcja;
        getline(ss, datetime, ',');
        ss >> autokonsumpcja;
        ss.ignore(numeric_limits<streamsize>::max(), ',');
        ss >> eksport;
        ss.ignore(numeric_limits<streamsize>::max(), ',');
        ss >> import;
        ss.ignore(numeric_limits<streamsize>::max(), ',');
        ss >> pobor;
        ss.ignore(numeric_limits<streamsize>::max(), ',');
        ss >> produkcja;

        data.push_back({ datetime, autokonsumpcja, eksport, import, pobor, produkcja });
    }
}

// Funkcja pomocnicza do konwersji daty i godziny na znacznik czasu (timestamp)

time_t convertToTimestamp(const string& datetime) {
    tm time = {};
    stringstream ss(datetime);
    ss >> get_time(&time, "%Y-%m-%d %H:%M:%S");
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

void DataTree::readBinaryFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku " << filename << endl;
        return;
    }

    DataPoint point;
    while (file.read(reinterpret_cast<char*>(&point), sizeof(point))) {
        data.push_back(point);
    }
}
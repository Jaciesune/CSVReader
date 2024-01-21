//treeData.h
#pragma once
#include "pointData.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
class DataTree {
private:
    // Wektor do przechowywania danych
    vector<DataPoint> data;

    // Metoda pomocnicza do konwersji daty i godziny na znacznik czasu (timestamp)
    time_t convertToTimestamp(const string& datetime);
    

public:
    // Metody opisane w treSci zadania
    void printAutokonsumpcjaSum(const string& start, const string& end);
    void printEksportSum(const string& start, const string& end);
    void printImportSum(const string& start, const string& end);
    void printPoborSum(const string& start, const string& end);
    void printProdukcjaSum(const string& start, const string& end);

    void printAutokonsumpcjaAverage(const string& start, const string& end);
    void printEksportAverage(const string& start, const string& end);
    void printImportAverage(const string& start, const string& end);
    void printPoborAverage(const string& start, const string& end);
    void printProdukcjaAverage(const string& start, const string& end);

    void compareAutokonsumpcja(const string& start1, const string& end1, const string& start2, const string& end2);
    void compareEksport(const string& start1, const string& end1, const string& start2, const string& end2);
    void compareImport(const string& start1, const string& end1, const string& start2, const string& end2);
    void comparePobor(const string& start1, const string& end1, const string& start2, const string& end2);
    void compareProdukcja(const string& start1, const string& end1, const string& start2, const string& end2);

    void searchAndPrint(const double value, const double tolerance, const string& start, const string& end);

    void saveBinaryFile(const string& filename);
    void readBinaryFile(const string& filename);
    // Function to add data to the private vector
    void addData(const DataPoint& point) {
        data.push_back(point);
    }

    // Metody do operacji na danych
    void loadDataFromFile(const string& filename);
    void printSummary();
};


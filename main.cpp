//program wyświetla menu i pozwala wybrać opcję
//wywołuje odpowiednią metodę z klasy DataTree
//wyświetla wynik działania metody
//powtarza działanie do momentu wybrania opcji 0
//
// Path: main.cpp
#include "treeData.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;




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
        void loadDataFromFile(const std::string& filename);

        case 1: {
            std::string filename;
            std::cout << "Podaj nazwe pliku: ";
            std::getline(std::cin, filename);
            loadDataFromFile(filename);
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


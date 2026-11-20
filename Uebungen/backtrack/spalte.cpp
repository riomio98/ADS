#include "common.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Aufruf: " << argv[0] << " <textdatei> [-w=<B>] [-z]\n";
        return 1;
    }

    try {
        int breite = 40;
        bool zeigeKosten = false;

        for (int i = 2; i < argc; ++i) {
            string arg = argv[i];
            if (arg == "-z") {
                zeigeKosten = true;
            } else if (arg.rfind("-w=", 0) == 0) {
                string wert = arg.substr(3);
                size_t gelesen = 0;
                breite = stoi(wert, &gelesen);
                if (gelesen != wert.size() || breite < 1) {
                    throw invalid_argument("Ungueltige Spaltenbreite: " + wert);
                }
            } else {
                throw invalid_argument("Unbekannte Option: " + arg);
            }
        }

        ifstream datei(argv[1]);
        if (!datei) {
            throw runtime_error("Datei konnte nicht geoeffnet werden: " + string(argv[1]));
        }

        vector<string> woerter;
        string wort;
        while (datei >> wort) {
            woerter.push_back(wort);
        }

        vector<pair<int, int>> zeilen = gierigerUmbruch(woerter, breite);

        cout << "--- Gieriger Umbruch (vorgegeben) ---\n";
        for (const auto& zeile : zeilen) {
            if (zeigeKosten) {
                cout << setw(5)
                     << zeilenkosten(woerter, breite, zeile.first, zeile.second)
                     << ' ';
            }
            for (int i = zeile.first; i <= zeile.second; ++i) {
                if (i > zeile.first) cout << ' ';
                cout << woerter[i];
            }
            cout << '\n';
        }
        cout << "Zeilen: " << zeilen.size()
             << ", Kosten: " << gierigeKosten(woerter, breite) << "\n";

        cout << "--- Rekursive Optimierung (deine Aufgabe) ---\n";
        cout << "Optimale Kosten: " << optimaleKosten(woerter, breite, 0) << "\n";
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << '\n';
        return 1;
    }

    return 0;
}

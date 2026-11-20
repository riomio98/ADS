#include "common.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Testfall {
    string name;
    vector<string> woerter;
    int breite;
    int start;
    long erwartet;
};

int main() {
    const vector<Testfall> testfaelle = {
        {"Leerer Text", {}, 6, 0, 0},
        {"Ein Wort", {"hallo"}, 5, 0, 0},
        {"Alle passen", {"aa", "bb"}, 5, 0, 0},
        {"Zwei getrennte Zeilen", {"ab", "cd"}, 3, 0, 1},
        {"Drei getrennte Zeilen", {"ab", "cd", "ef"}, 4, 0, 8},
        {"Greedy nicht optimal", {"aaa", "bb", "cc", "ddddd"}, 6, 0, 10},
        {"Nur der Resttext", {"aaa", "bb", "cc", "ddddd"}, 6, 1, 1},
        {"Letzte Zeile frei", {"ab", "cde"}, 4, 0, 4},
        {"Leerer Restbereich", {"ab", "cd"}, 4, 2, 0}
    };

    int bestanden = 0;
    for (const Testfall& t : testfaelle) {
        long ergebnis = optimaleKosten(t.woerter, t.breite, t.start);
        bool ok = ergebnis == t.erwartet;
        cout << (ok ? "OK    " : "FEHLER")
             << " | " << t.name
             << " | erwartet: " << t.erwartet
             << ", erhalten: " << ergebnis << '\n';
        if (ok) ++bestanden;
    }

    cout << "\nBestanden: " << bestanden << "/" << testfaelle.size() << '\n';
    return bestanden == static_cast<int>(testfaelle.size()) ? 0 : 1;
}

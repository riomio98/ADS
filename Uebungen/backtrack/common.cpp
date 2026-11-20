#include "common.h"

#include <stdexcept>
#include <climits>

using namespace std;

long zeilenbreite(const vector<string>& woerter, int start, int ende) {
    if (start < 0 || ende < start || ende >= static_cast<int>(woerter.size())) {
        throw out_of_range("Ungueltiger Wortbereich");
    }

    long laenge = ende - start; // Zwischenraeume: ein Leerzeichen je Wortpaar
    for (int i = start; i <= ende; ++i) {
        laenge += static_cast<long>(woerter[i].size());
    }
    return laenge;
}

long zeilenkosten(const vector<string>& woerter,
                  int breite, int start, int ende) {
    long laenge = zeilenbreite(woerter, start, ende);
    if (laenge > breite) {
        throw invalid_argument("Die Zeile ist breiter als die Spalte");
    }

    if (ende == static_cast<int>(woerter.size()) - 1) {
        return 0; // Die letzte Zeile ist kostenfrei.
    }

    long frei = breite - laenge;
    return frei * frei;
}

vector<pair<int, int>> gierigerUmbruch(const vector<string>& woerter,
                                      int breite) {
    if (breite < 1) {
        throw invalid_argument("Spaltenbreite muss positiv sein");
    }

    for (const string& wort : woerter) {
        if (static_cast<int>(wort.size()) > breite) {
            throw invalid_argument("Wort ist breiter als die Spalte: " + wort);
        }
    }

    vector<pair<int, int>> zeilen;
    int i = 0;
    int anzahl = static_cast<int>(woerter.size());

    while (i < anzahl) {
        int beginn = i;
        long benutzt = static_cast<long>(woerter[i].size());
        ++i;

        while (i < anzahl &&
               benutzt + 1 + static_cast<long>(woerter[i].size()) <= breite) {
            benutzt += 1 + static_cast<long>(woerter[i].size());
            ++i;
        }

        zeilen.push_back({beginn, i - 1});
    }

    return zeilen;
}

long gierigeKosten(const vector<string>& woerter, int breite) {
    long summe = 0;
    for (const auto& zeile : gierigerUmbruch(woerter, breite)) {
        summe += zeilenkosten(woerter, breite, zeile.first, zeile.second);
    }
    return summe;
}

long optimaleKosten(const vector<string>& woerter, int breite, int  start )
{
    // Diese Zeilen sind nur Platzhalter, damit das Projekt kompiliert.
	if(start == static_cast<int>(woerter.size()))
	{
		return 0;
	}
	long best_cost = LONG_MAX;
	for(int ende = start; ende < static_cast<int>(woerter.size()); ende++)
	{
		if(static_cast<int>(woerter[ende].size()) > breite)
		{
			throw runtime_error("wort zu lang");
		}

		int zb = zeilenbreite(woerter, start, ende);
		if (zb > breite)
		{
		    break;
		}
		long actual_cost = zeilenkosten(woerter, breite, start, ende);
		if(zb <= breite)
		{
			long gesamt = actual_cost + optimaleKosten(woerter, breite, ende + 1);
			if(gesamt < best_cost)
			{
				best_cost = gesamt;
			}
		}
	}

    return best_cost;
}

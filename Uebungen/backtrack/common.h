#ifndef ADS_COMMON_H
#define ADS_COMMON_H

#include <string>
#include <utility>
#include <vector>

// Die Indizes start und ende sind jeweils inklusive.
long zeilenbreite(const std::vector<std::string>& woerter,
                  int start, int ende);

// Die letzte Zeile kostet 0, sofern alle Woerter hineinpassen.
long zeilenkosten(const std::vector<std::string>& woerter,
                  int breite, int start, int ende);

// Ein Paar speichert (Startindex, Endindex) einer Zeile.
std::vector<std::pair<int, int>> gierigerUmbruch(
    const std::vector<std::string>& woerter, int breite);

long gierigeKosten(const std::vector<std::string>& woerter, int breite);

// TESTATAUFGABE: Berechne die minimalen Kosten fuer die Woerter
// im Bereich [start, woerter.size()).
// Voraussetzung: breite >= 1 und jedes Wort ist hoechstens breite Zeichen lang.
// Gueltig sind 0 <= start <= woerter.size().
long optimaleKosten(const std::vector<std::string>& woerter,
                    int breite, int start);





#endif

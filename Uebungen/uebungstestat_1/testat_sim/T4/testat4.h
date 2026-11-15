// testat4.h - Probetestat 4: Halbieren: kleinste Spaltenbreite
// Diese Datei ist vorgegeben und darf NICHT geaendert werden.
#ifndef TESTAT4_H
#define TESTAT4_H

#include <string>
#include <vector>
#include <utility>

using text_t = std::vector<std::string>;
using zeilen_t = std::vector<int>;   // Index des ersten Wortes jeder Zeile (wie im Miniprojekt)

// Teil 0: umbruch aus common.h muss einen const-Text annehmen koennen (siehe Aufgabenblatt).
int laengste_wortlaenge(const text_t& text);                              // 0 bei leerem Text
int anzahl_zeilen(const text_t& text, int b);                             // Zeilen des gierigen Umbruchs
int min_breite_rek(const text_t& text, int max_zeilen, int lo, int hi);   // REKURSIVE binaere Suche in [lo, hi]
int min_breite(const text_t& text, int max_zeilen);                       // kleinste Breite mit hoechstens max_zeilen Zeilen

#endif

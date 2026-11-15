// testat3.h - Probetestat 3: Teile und Herrsche
// Diese Datei ist vorgegeben und darf NICHT geaendert werden.
#ifndef TESTAT3_H
#define TESTAT3_H

#include <string>
#include <vector>
#include <utility>

using text_t = std::vector<std::string>;
using zeilen_t = std::vector<int>;   // Index des ersten Wortes jeder Zeile (wie im Miniprojekt)

// Alle Funktionen mit TEILE UND HERRSCHE auf dem Bereich [lo, hi] (hi INKLUSIV), Voraussetzung lo <= hi.
int laengstes_wort(const text_t& text, int lo, int hi);                   // INDEX des laengsten Wortes; Gleichstand: kleinster Index
long summe_laengen(const text_t& text, int lo, int hi);                   // Summe der Wortlaengen (ohne Leerzeichen)
int anzahl_vorkommen(const text_t& text, const std::string& w, int lo, int hi); // wie oft steht w genau so im Bereich?
int laengster_gleichlang_lauf(const text_t& text, int lo, int hi);        // laengste Folge benachbarter Woerter gleicher Laenge
long kosten_zeile(const text_t& text, const zeilen_t& zeilen, int b, int k); // Kosten der Zeile k (letzte Zeile: 0) - darf eine Schleife sein
int teuerste_zeile(const text_t& text, const zeilen_t& zeilen, int b, int lo, int hi); // Zeilenindex mit hoechsten Kosten in [lo, hi]; Gleichstand: kleinster

#endif

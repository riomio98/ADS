// testat7.h - Probetestat 7: Umbruch auf fuenf Arten
// Diese Datei ist vorgegeben und darf NICHT geaendert werden.
#ifndef TESTAT7_H
#define TESTAT7_H

#include <string>
#include <vector>
#include <utility>

using text_t = std::vector<std::string>;
using zeilen_t = std::vector<int>;   // Index des ersten Wortes jeder Zeile (wie im Miniprojekt)

// Alle Umbruch-Varianten muessen GENAU dasselbe liefern wie umbruch aus dem Miniprojekt
// (gierig, Zeilenanfaenge, leerer Text -> leerer vector, Wort breiter als b -> std::runtime_error).

// Art 1: iterativ, aber ZEILENWEISE (aeussere Schleife pro Zeile, innere fuellt die Zeile)
zeilen_t umbruch_zeilenweise(const text_t& text, int b);

// Art 2: REKURSIV zeilenweise, Ergebnis als Rueckgabewert: Zeilenanfaenge fuer text[start..]
zeilen_t umbruch_zeilen_rek(const text_t& text, int start, int b);

// Art 3: ENDREKURSIV zeilenweise: haengt die Zeilenanfaenge fuer text[start..] HINTEN an zeilen an
void umbruch_endrek(const text_t& text, int start, int b, zeilen_t& zeilen);

// Art 4: Praefixsummen - Zeilenbreite in O(1)
std::vector<long> praefix(const text_t& text);                               // P[0] = 0, P[i+1] = P[i] + Laenge von text[i]
long breite_p(const std::vector<long>& P, int von, int bis);                 // wie zeilenbreite(text, von, bis), aber ohne Schleife

// Art 5: Zeilenende durch HALBIEREN (rekursive binaere Suche)
int zeilenende(const std::vector<long>& P, int start, int b, int lo, int hi); // groesstes ende in [lo, hi] mit breite_p(P, start, ende) <= b
zeilen_t umbruch_binaer(const text_t& text, int b);

// Kosten rekursiv ueber die Zeilen, mit Praefixsummen
long gesamtkosten_rek(const std::vector<long>& P, const zeilen_t& zeilen, int b, int k); // Kosten der Zeilen k, k+1, ... (letzte Zeile 0)

// Bonus: gierig VON HINTEN - die letzte Zeile so voll wie moeglich, dann die vorletzte usw.
zeilen_t umbruch_von_hinten(const text_t& text, int b);

#endif

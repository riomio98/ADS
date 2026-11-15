// testat5.h - Probetestat 5: Backtracking: Umbrueche aufzaehlen
// Diese Datei ist vorgegeben und darf NICHT geaendert werden.
#ifndef TESTAT5_H
#define TESTAT5_H

#include <string>
#include <vector>
#include <utility>

using text_t = std::vector<std::string>;
using zeilen_t = std::vector<int>;   // Index des ersten Wortes jeder Zeile (wie im Miniprojekt)

// Reihenfolge ALLER Aufzaehlungen: die erste Zeile zuerst so KURZ wie moeglich (ein Wort), dann laenger;
// fuer den Rest gilt rekursiv dieselbe Regel.
std::vector<zeilen_t> alle_umbrueche(const text_t& text, int b);          // alle zulaessigen Umbrueche in dieser Reihenfolge
zeilen_t umbruch_k_zeilen(const text_t& text, int b, int k);              // erster Umbruch mit genau k Zeilen, sonst {}
long min_kosten(const text_t& text, int b, zeilen_t& beste);              // minimale Kosten; beste = erster optimaler Umbruch

#endif

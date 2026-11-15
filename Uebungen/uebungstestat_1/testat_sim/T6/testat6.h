// testat6.h - Probetestat 6: MergeSort nach Wortlaenge
// Diese Datei ist vorgegeben und darf NICHT geaendert werden.
#ifndef TESTAT6_H
#define TESTAT6_H

#include <string>
#include <vector>
#include <utility>

using text_t = std::vector<std::string>;
using zeilen_t = std::vector<int>;   // Index des ersten Wortes jeder Zeile (wie im Miniprojekt)

// Eigene Implementierung - std::sort, std::stable_sort u. ae. sind nicht erlaubt.
void merge_laenge(text_t& a, int lo, int mi, int hi);                     // a[lo..mi] und a[mi+1..hi] sortiert -> a[lo..hi] sortiert, STABIL
void mergesort_laenge(text_t& a, int lo, int hi);                         // rekursiv, aufsteigend nach Laenge, STABIL
text_t sortiert_nach_laenge(const text_t& text);                          // sortierte Kopie
text_t k_laengste(const text_t& text, int k);                             // k laengste Woerter, laengste zuerst; Gleichstand: Reihenfolge wie im Text

#endif

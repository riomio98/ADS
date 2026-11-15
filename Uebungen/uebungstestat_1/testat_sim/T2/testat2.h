// testat2.h - Probetestat 2: Zeilen setzen
// Diese Datei ist vorgegeben und darf NICHT geaendert werden.
#ifndef TESTAT2_H
#define TESTAT2_H

#include <string>
#include <vector>
#include <utility>

using text_t = std::vector<std::string>;
using zeilen_t = std::vector<int>;   // Index des ersten Wortes jeder Zeile (wie im Miniprojekt)

std::string zeile(const text_t& text, int von, int bis);                  // REKURSIV: text[von..bis-1] mit genau einem Leerzeichen
std::string rechtsbuendig(const text_t& text, int von, int bis, int b);   // links mit Leerzeichen auf Breite b auffuellen
std::string blocksatz(const text_t& text, int von, int bis, int b);       // Leerzeichen auf die Luecken verteilen
std::vector<std::string> setze(const text_t& text, const zeilen_t& zeilen, int b, char modus); // 'l', 'r' oder 'b'

#endif

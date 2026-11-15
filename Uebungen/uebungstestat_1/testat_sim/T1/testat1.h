// testat1.h - Probetestat 1: Rekursion ohne Schleifen
// Diese Datei ist vorgegeben und darf NICHT geaendert werden.
#ifndef TESTAT1_H
#define TESTAT1_H

#include <string>
#include <vector>
#include <utility>

using text_t = std::vector<std::string>;
using zeilen_t = std::vector<int>;   // Index des ersten Wortes jeder Zeile (wie im Miniprojekt)

// Alle Funktionen in dieser Datei sind REKURSIV zu loesen: kein for, kein while, kein do.
int anzahl_lang(const text_t& text, int idx, int min_len);               // Woerter ab idx mit Laenge >= min_len
std::string umdrehen(const std::string& w);                               // "Spalte" -> "etlapS"
bool ist_palindrom(const std::string& w, int lo, int hi);                 // w[lo..hi], Gross/Klein egal
int zaehle_zeichen(const std::string& w, char c, int i);                  // Vorkommen von c in w[i..], Gross/Klein zaehlt
std::string verbinde(const text_t& text, int von, int bis, const std::string& sep); // text[von..bis-1], getrennt durch sep
int index_von(const text_t& text, const std::string& wort, int idx);      // erstes Vorkommen ab idx, sonst -1
int anzahl_palindrome(const text_t& text, int idx);                       // Palindrom-Woerter ab idx

#endif

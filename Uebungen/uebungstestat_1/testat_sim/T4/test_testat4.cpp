#include "alltest.h"
#include "testat4.h"
#include "common.h"
#include "pbma.h"
#include <chrono>
#include <random>
#include <stdexcept>

using namespace std;

TEST(Halbieren, ConstText) {
    const text_t ct = read_words("beispiel.txt");            // const! -> umbruch muss const text_t& annehmen
    EXPECT_EQ(umbruch(ct, 29), (zeilen_t{0, 5, 10, 13}));
    EXPECT_EQ(anzahl_zeilen(ct, 29), 4);
}

TEST(Halbieren, LaengsteWortlaenge) {
    EXPECT_EQ(laengste_wortlaenge(read_words("beispiel.txt")), 14);
    EXPECT_EQ(laengste_wortlaenge({}), 0);
    EXPECT_EQ(laengste_wortlaenge({"a"}), 1);
}

TEST(Halbieren, AnzahlZeilen) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(anzahl_zeilen(t, 90), 1);
    EXPECT_EQ(anzahl_zeilen(t, 89), 2);
    EXPECT_EQ(anzahl_zeilen(t, 14), 7);
    EXPECT_THROW(anzahl_zeilen(t, 13), std::runtime_error);  // "Silbentrennung" passt nicht
}

TEST(Halbieren, MinBreiteBeispiel) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(min_breite(t, 1), 90);                         // alles in einer Zeile
    EXPECT_EQ(min_breite(t, 2), 46);
    EXPECT_EQ(min_breite(t, 3), 32);
    EXPECT_EQ(min_breite(t, 4), 24);
    EXPECT_EQ(min_breite(t, 5), 20);
    EXPECT_EQ(min_breite(t, 8), 14);                         // schmaler als das laengste Wort geht nicht
    EXPECT_EQ(min_breite(t, 100), 14);
}

TEST(Halbieren, MinBreiteRek) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(min_breite_rek(t, 4, 14, 90), 24);
    EXPECT_EQ(min_breite_rek(t, 4, 24, 24), 24);             // nur ein Kandidat
    EXPECT_EQ(min_breite_rek(t, 4, 30, 90), 30);             // Suche nur in [lo, hi]
}

TEST(Halbieren, Randfaelle) {
    text_t leer;
    EXPECT_EQ(min_breite(leer, 3), 0);
    text_t t = {"abc"};
    EXPECT_EQ(min_breite(t, 1), 3);
    EXPECT_THROW(min_breite(t, 0), std::invalid_argument);
    EXPECT_THROW(min_breite(t, -2), std::invalid_argument);
}

TEST(Halbieren, WirklichMinimal) {
    mt19937 rng(99);
    uniform_int_distribution<int> len(1, 8);
    for (int k = 0; k < 60; k++) {
        text_t t;
        for (int i = 0; i < 5 + k; i++) t.push_back(string(len(rng), 'q'));
        for (int z : {1, 2, 3, 5, 8}) {
            int b = min_breite(t, z);
            EXPECT_LE(anzahl_zeilen(t, b), z);                   // b reicht
            if (b > laengste_wortlaenge(t)) {
                EXPECT_GT(anzahl_zeilen(t, b - 1), z);           // b - 1 reicht nicht
            }
        }
    }
}

TEST(Halbieren, SchnellGenug) {
    // Wer alle Breiten der Reihe nach probiert, ist hier viel zu langsam.
    mt19937 rng(7);
    uniform_int_distribution<int> len(1, 9);
    text_t t;
    for (int i = 0; i < 20000; i++) t.push_back(string(len(rng), 'w'));
    auto start = chrono::steady_clock::now();
    int b = min_breite(t, 2);
    auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
    EXPECT_LE(anzahl_zeilen(t, b), 2);
    EXPECT_GT(anzahl_zeilen(t, b - 1), 2);
    EXPECT_LT(ms, 1000) << "min_breite brauchte " << ms << " ms";
}

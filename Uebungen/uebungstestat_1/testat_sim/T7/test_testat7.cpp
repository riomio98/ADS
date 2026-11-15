#include "alltest.h"
#include "testat7.h"
#include "common.h"
#include "pbma.h"
#include <random>
#include <stdexcept>

using namespace std;

static text_t zufall(mt19937& rng, int n, int maxlen) {
    uniform_int_distribution<int> len(1, maxlen);
    text_t t;
    for (int i = 0; i < n; i++) t.push_back(string(len(rng), 'a' + i % 26));
    return t;
}

// ---------------------------------------------------------------- Art 1
TEST(Zeilenweise, Beispiel) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(umbruch_zeilenweise(t, 29), (zeilen_t{0, 5, 10, 13}));
    for (int b = 14; b <= 95; b++) EXPECT_EQ(umbruch_zeilenweise(t, b), umbruch(t, b)) << "b = " << b;
}
TEST(Zeilenweise, Rand) {
    text_t leer;
    EXPECT_TRUE(umbruch_zeilenweise(leer, 10).empty());
    EXPECT_EQ(umbruch_zeilenweise({"abcde"}, 5), (zeilen_t{0}));           // Wort genau b
    EXPECT_EQ(umbruch_zeilenweise({"ab", "cd"}, 5), (zeilen_t{0}));        // 2 + 1 + 2 = 5 passt genau
    EXPECT_EQ(umbruch_zeilenweise({"ab", "cd"}, 4), (zeilen_t{0, 1}));
    EXPECT_THROW(umbruch_zeilenweise({"ok", "abcdef"}, 5), std::runtime_error);
}
TEST(Zeilenweise, GrosserText) {
    mt19937 rng(1);
    text_t t = zufall(rng, 200000, 9);
    EXPECT_EQ(umbruch_zeilenweise(t, 29), umbruch(t, 29));
}

// ---------------------------------------------------------------- Art 2
TEST(ZeilenRek, Beispiel) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(umbruch_zeilen_rek(t, 0, 29), (zeilen_t{0, 5, 10, 13}));
    EXPECT_EQ(umbruch_zeilen_rek(t, 5, 29), (zeilen_t{5, 10, 13}));        // erst ab Wort 5
    EXPECT_EQ(umbruch_zeilen_rek(t, 13, 29), (zeilen_t{13}));
    EXPECT_TRUE(umbruch_zeilen_rek(t, 14, 29).empty());                    // am Ende: nichts mehr
}
TEST(ZeilenRek, Rand) {
    text_t leer;
    EXPECT_TRUE(umbruch_zeilen_rek(leer, 0, 10).empty());
    EXPECT_THROW(umbruch_zeilen_rek({"ok", "abcdef", "ok"}, 0, 5), std::runtime_error);
}
TEST(ZeilenRek, Zufall) {
    mt19937 rng(2);
    for (int k = 0; k < 200; k++) {
        text_t t = zufall(rng, k % 60, 9);
        int b = 9 + k % 25;
        EXPECT_EQ(umbruch_zeilen_rek(t, 0, b), umbruch(t, b));
    }
}

// ---------------------------------------------------------------- Art 3
TEST(Endrek, Beispiel) {
    text_t t = read_words("beispiel.txt");
    zeilen_t z;
    umbruch_endrek(t, 0, 29, z);
    EXPECT_EQ(z, (zeilen_t{0, 5, 10, 13}));
}
TEST(Endrek, HaengtHintenAn) {
    text_t t = read_words("beispiel.txt");
    zeilen_t z = {0, 5};                                   // die ersten zwei Zeilen stehen schon fest
    umbruch_endrek(t, 10, 29, z);
    EXPECT_EQ(z, (zeilen_t{0, 5, 10, 13}));                // nicht ueberschreiben, anhaengen
}
TEST(Endrek, Zufall) {
    mt19937 rng(3);
    for (int k = 0; k < 200; k++) {
        text_t t = zufall(rng, k % 60, 9);
        int b = 9 + k % 25;
        zeilen_t z;
        umbruch_endrek(t, 0, b, z);
        EXPECT_EQ(z, umbruch(t, b));
    }
    zeilen_t z;
    EXPECT_THROW(umbruch_endrek({"abcdef"}, 0, 5, z), std::runtime_error);
}

// ---------------------------------------------------------------- Art 4
TEST(Praefix, Werte) {
    text_t t = read_words("beispiel.txt");
    vector<long> P = praefix(t);
    ASSERT_EQ(P.size(), t.size() + 1);                     // ein Eintrag mehr als Woerter
    EXPECT_EQ(P[0], 0);
    EXPECT_EQ(P[1], 3);                                    // "Ein"
    EXPECT_EQ(P[2], 8);                                    // + "guter"
    EXPECT_EQ(P[14], 77);
    text_t leer;
    EXPECT_EQ(praefix(leer), (vector<long>{0}));
}
TEST(Praefix, Breite) {
    text_t t = read_words("beispiel.txt");
    vector<long> P = praefix(t);
    EXPECT_EQ(breite_p(P, 0, 5), 27);
    EXPECT_EQ(breite_p(P, 5, 10), 29);
    EXPECT_EQ(breite_p(P, 0, 14), 90);
    EXPECT_EQ(breite_p(P, 13, 14), 14);                    // ein Wort: kein Leerzeichen
    EXPECT_EQ(breite_p(P, 4, 4), 0);                       // leerer Bereich
    for (int von = 0; von <= 14; von++)
        for (int bis = von; bis <= 14; bis++) EXPECT_EQ(breite_p(P, von, bis), zeilenbreite(t, von, bis));
}

// ---------------------------------------------------------------- Art 5
TEST(Binaer, Zeilenende) {
    text_t t = read_words("beispiel.txt");
    vector<long> P = praefix(t);
    EXPECT_EQ(zeilenende(P, 0, 29, 1, 14), 5);
    EXPECT_EQ(zeilenende(P, 5, 29, 6, 14), 10);            // Zeile passt genau (29)
    EXPECT_EQ(zeilenende(P, 10, 29, 11, 14), 13);
    EXPECT_EQ(zeilenende(P, 0, 90, 1, 14), 14);            // alles passt: hi
    EXPECT_EQ(zeilenende(P, 0, 3, 1, 14), 1);              // nur lo passt
    EXPECT_EQ(zeilenende(P, 0, 29, 3, 3), 3);              // ein Kandidat
    EXPECT_EQ(zeilenende(P, 0, 29, 2, 4), 4);              // nur in [lo, hi] suchen
}
TEST(Binaer, Umbruch) {
    text_t t = read_words("beispiel.txt");
    for (int b = 14; b <= 95; b++) EXPECT_EQ(umbruch_binaer(t, b), umbruch(t, b)) << "b = " << b;
    text_t leer;
    EXPECT_TRUE(umbruch_binaer(leer, 10).empty());
    EXPECT_THROW(umbruch_binaer({"ok", "abcdef"}, 5), std::runtime_error);
}
TEST(Binaer, Zufall) {
    mt19937 rng(4);
    for (int k = 0; k < 300; k++) {
        text_t t = zufall(rng, k % 80, 9);
        int b = 9 + k % 30;
        EXPECT_EQ(umbruch_binaer(t, b), umbruch(t, b));
    }
    text_t gross = zufall(rng, 200000, 9);
    EXPECT_EQ(umbruch_binaer(gross, 40), umbruch(gross, 40));
}

// ---------------------------------------------------------------- Kosten
TEST(Kosten, Rekursiv) {
    text_t t = read_words("beispiel.txt");
    vector<long> P = praefix(t);
    EXPECT_EQ(gesamtkosten_rek(P, umbruch(t, 29), 29, 0), 148);
    EXPECT_EQ(gesamtkosten_rek(P, umbruch(t, 29), 29, 2), 144);   // nur ab Zeile 2
    EXPECT_EQ(gesamtkosten_rek(P, umbruch(t, 29), 29, 3), 0);     // letzte Zeile
    EXPECT_EQ(gesamtkosten_rek(P, {}, 29, 0), 0);
    mt19937 rng(5);
    for (int k = 0; k < 200; k++) {
        text_t r = zufall(rng, 1 + k % 60, 9);
        int b = 9 + k % 25;
        zeilen_t z = umbruch(r, b);
        EXPECT_EQ(gesamtkosten_rek(praefix(r), z, b, 0), gesamtkosten(r, z, b));
    }
}

// ---------------------------------------------------------------- Bonus
TEST(Bonus, VonHinten) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(umbruch_von_hinten(t, 29), (zeilen_t{0, 2, 6, 11}));
    EXPECT_EQ(gesamtkosten(t, umbruch_von_hinten(t, 29), 29), 432);   // vorne: 148
    EXPECT_EQ(umbruch_von_hinten(t, 40), (zeilen_t{0, 3, 9}));
    EXPECT_EQ(umbruch_von_hinten(t, 20), umbruch(t, 20));            // hier zufaellig gleich
    text_t k = {"aaa", "bb", "cc", "ddddd"};
    EXPECT_EQ(umbruch_von_hinten(k, 6), (zeilen_t{0, 1, 3}));         // hier BESSER als vorne (10 statt 16)
    text_t leer;
    EXPECT_TRUE(umbruch_von_hinten(leer, 5).empty());
    EXPECT_THROW(umbruch_von_hinten({"abcdef", "ok"}, 5), std::runtime_error);
}

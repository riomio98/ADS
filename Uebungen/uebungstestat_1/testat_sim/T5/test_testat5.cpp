#include "alltest.h"
#include "testat5.h"
#include "common.h"
#include "pbma.h"
#include <stdexcept>

using namespace std;

TEST(Backtracking, AlleKlein) {
    text_t t = {"aaa", "bb", "cc", "ddddd"};
    vector<zeilen_t> soll = {{0, 1, 2, 3}, {0, 1, 3}, {0, 2, 3}};   // genau diese Reihenfolge
    EXPECT_EQ(alle_umbrueche(t, 6), soll);
}

TEST(Backtracking, AlleReihenfolge) {
    text_t t = {"a", "b", "c"};
    vector<zeilen_t> soll = {{0, 1, 2}, {0, 1}, {0, 2}, {0}};
    EXPECT_EQ(alle_umbrueche(t, 5), soll);                   // "a b c" passt ganz in eine Zeile
    vector<zeilen_t> soll3 = {{0, 1, 2}, {0, 1}, {0, 2}};
    EXPECT_EQ(alle_umbrueche(t, 3), soll3);
}

TEST(Backtracking, AlleRand) {
    text_t leer;
    EXPECT_EQ(alle_umbrueche(leer, 5), vector<zeilen_t>{zeilen_t{}});   // genau ein (leerer) Umbruch
    text_t breit = {"ok", "vielzubreit"};
    EXPECT_TRUE(alle_umbrueche(breit, 5).empty());           // kein zulaessiger Umbruch
    text_t eins = {"ab"};
    EXPECT_EQ(alle_umbrueche(eins, 2), vector<zeilen_t>{zeilen_t{0}});
}

TEST(Backtracking, AnzahlBeispiel) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(alle_umbrueche(t, 29).size(), 6012u);
    for (const zeilen_t& z : alle_umbrueche(t, 40)) {        // jeder Umbruch ist zulaessig
        ASSERT_FALSE(z.empty());
        EXPECT_EQ(z[0], 0);
        for (size_t k = 0; k < z.size(); k++) {
            int ende = (k + 1 < z.size()) ? z[k + 1] : t.size();
            EXPECT_LE(zeilenbreite(t, z[k], ende), 40);
        }
    }
}

TEST(Backtracking, KZeilen) {
    text_t t = {"aaa", "bb", "cc", "ddddd"};
    EXPECT_EQ(umbruch_k_zeilen(t, 6, 3), (zeilen_t{0, 1, 3}));   // der ERSTE mit 3 Zeilen
    EXPECT_EQ(umbruch_k_zeilen(t, 6, 4), (zeilen_t{0, 1, 2, 3}));
    EXPECT_TRUE(umbruch_k_zeilen(t, 6, 2).empty());
    EXPECT_TRUE(umbruch_k_zeilen(t, 6, 5).empty());
    EXPECT_TRUE(umbruch_k_zeilen(t, 6, 0).empty());
    text_t b = read_words("beispiel.txt");
    EXPECT_EQ(umbruch_k_zeilen(b, 29, 4), (zeilen_t{0, 2, 6, 11}));
    EXPECT_EQ(umbruch_k_zeilen(b, 29, 5), (zeilen_t{0, 1, 2, 6, 11}));
    EXPECT_TRUE(umbruch_k_zeilen(b, 29, 3).empty());
}

TEST(Backtracking, MinKosten) {
    text_t t = {"aaa", "bb", "cc", "ddddd"};
    zeilen_t beste;
    EXPECT_EQ(min_kosten(t, 6, beste), 10);
    EXPECT_EQ(beste, (zeilen_t{0, 1, 3}));
    text_t b = read_words("beispiel.txt");
    EXPECT_EQ(min_kosten(b, 29, beste), 78);                 // gierig waeren es 148
    EXPECT_EQ(beste, (zeilen_t{0, 4, 9, 13}));
}

TEST(Backtracking, MinKostenGleichstand) {
    text_t t = {"a", "b", "c", "dd"};                        // {0,1,3} und {0,2,3} kosten beide 4
    zeilen_t beste;
    EXPECT_EQ(min_kosten(t, 3, beste), 4);
    EXPECT_EQ(beste, (zeilen_t{0, 1, 3}));                   // der zuerst aufgezaehlte
}

TEST(Backtracking, MinKostenRand) {
    text_t leer;
    zeilen_t beste = {7, 7};
    EXPECT_EQ(min_kosten(leer, 5, beste), 0);
    EXPECT_TRUE(beste.empty());                              // beste wird ueberschrieben
    text_t breit = {"ok", "vielzubreit"};
    EXPECT_THROW(min_kosten(breit, 5, beste), std::runtime_error);
}

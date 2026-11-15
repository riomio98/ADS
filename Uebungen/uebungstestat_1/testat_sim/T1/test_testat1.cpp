#include "alltest.h"
#include "testat1.h"
#include "pbma.h"

using namespace std;

TEST(Rekursion, AnzahlLang) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(anzahl_lang(t, 0, 5), 9);
    EXPECT_EQ(anzahl_lang(t, 0, 7), 4);
    EXPECT_EQ(anzahl_lang(t, 0, 0), 14);         // jedes Wort hat Laenge >= 0
    EXPECT_EQ(anzahl_lang(t, 13, 14), 1);        // nur "Silbentrennung"
    EXPECT_EQ(anzahl_lang(t, 14, 1), 0);         // idx am Ende
    EXPECT_EQ(anzahl_lang(t, 20, 1), 0);         // idx hinter dem Ende
    text_t leer;
    EXPECT_EQ(anzahl_lang(leer, 0, 3), 0);
}

TEST(Rekursion, Umdrehen) {
    EXPECT_EQ(umdrehen("Spalte"), "etlapS");
    EXPECT_EQ(umdrehen("ab"), "ba");
    EXPECT_EQ(umdrehen("a"), "a");
    EXPECT_EQ(umdrehen(""), "");
    EXPECT_EQ(umdrehen("Otto"), "ottO");         // Gross/Klein bleibt erhalten
}

TEST(Rekursion, Palindrom) {
    auto pal = [](const string& w) { return ist_palindrom(w, 0, (int)w.size() - 1); };
    EXPECT_TRUE(pal("Anna"));                    // Gross/Klein egal
    EXPECT_TRUE(pal("Rentner"));
    EXPECT_TRUE(pal("otto"));
    EXPECT_TRUE(pal("aA"));
    EXPECT_TRUE(pal("a"));
    EXPECT_TRUE(pal(""));                        // leeres Wort ist ein Palindrom
    EXPECT_FALSE(pal("ab"));
    EXPECT_FALSE(pal("abca"));
    EXPECT_FALSE(pal("Spalte"));
    EXPECT_TRUE(ist_palindrom("xAnnay", 1, 4));  // nur der Bereich zaehlt
}

TEST(Rekursion, ZaehleZeichen) {
    EXPECT_EQ(zaehle_zeichen("Silbentrennung", 'n', 0), 4);
    EXPECT_EQ(zaehle_zeichen("Silbentrennung", 'N', 0), 0);   // Gross/Klein zaehlt hier!
    EXPECT_EQ(zaehle_zeichen("Silbentrennung", 'S', 0), 1);
    EXPECT_EQ(zaehle_zeichen("Silbentrennung", 'S', 1), 0);   // erst ab i zaehlen
    EXPECT_EQ(zaehle_zeichen("", 'a', 0), 0);
}

TEST(Rekursion, Verbinde) {
    text_t t = {"Ein", "guter", "Umbruch"};
    EXPECT_EQ(verbinde(t, 0, 3, " "), "Ein guter Umbruch");
    EXPECT_EQ(verbinde(t, 0, 3, ", "), "Ein, guter, Umbruch");
    EXPECT_EQ(verbinde(t, 0, 3, ""), "EinguterUmbruch");
    EXPECT_EQ(verbinde(t, 1, 2, "-"), "guter");              // ein Wort: kein Trenner
    EXPECT_EQ(verbinde(t, 2, 2, "-"), "");                   // leerer Bereich
    EXPECT_EQ(verbinde(t, 3, 1, "-"), "");                   // von > bis: leer
}

TEST(Rekursion, IndexVon) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(index_von(t, "Ein", 0), 0);
    EXPECT_EQ(index_von(t, "am", 0), 4);
    EXPECT_EQ(index_von(t, "Silbentrennung", 0), 13);
    EXPECT_EQ(index_von(t, "am", 5), -1);                    // erst ab idx suchen
    EXPECT_EQ(index_von(t, "Am", 0), -1);                    // exakt vergleichen
    EXPECT_EQ(index_von(t, "Umbruc", 0), -1);                // nur ganze Woerter
    text_t d = {"x", "y", "x"};
    EXPECT_EQ(index_von(d, "x", 0), 0);                      // das ERSTE Vorkommen
    EXPECT_EQ(index_von(d, "x", 1), 2);
}

TEST(Rekursion, AnzahlPalindrome) {
    text_t t = {"Anna", "und", "Otto", "a", "xy", "Rentner"};
    EXPECT_EQ(anzahl_palindrome(t, 0), 4);
    EXPECT_EQ(anzahl_palindrome(t, 2), 3);
    EXPECT_EQ(anzahl_palindrome(t, 6), 0);
}

TEST(Rekursion, VieleWoerter) {
    text_t t(2000, "abc");
    t[1999] = "lang_genug";
    EXPECT_EQ(anzahl_lang(t, 0, 3), 2000);
    EXPECT_EQ(anzahl_lang(t, 0, 4), 1);
    EXPECT_EQ(index_von(t, "lang_genug", 0), 1999);
}

#include "alltest.h"
#include "testat3.h"
#include "common.h"
#include "pbma.h"
#include <random>

using namespace std;

static text_t zufall(mt19937& rng, int n, int maxlen) {
    uniform_int_distribution<int> len(1, maxlen);
    text_t t;
    for (int i = 0; i < n; i++) t.push_back(string(len(rng), 'a' + i % 3));
    return t;
}

TEST(TeileHerrsche, LaengstesWort) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(laengstes_wort(t, 0, 13), 13);
    EXPECT_EQ(laengstes_wort(t, 0, 12), 2);                  // "Umbruch" (7) vor "rechten" und "braucht"
    EXPECT_EQ(laengstes_wort(t, 4, 4), 4);
    text_t g = {"ab", "cd", "x", "ef"};
    EXPECT_EQ(laengstes_wort(g, 0, 3), 0);                   // Gleichstand: kleinster Index
    text_t h = {"a", "bb", "cc"};
    EXPECT_EQ(laengstes_wort(h, 0, 2), 1);                   // Gleichstand ueber die Haelften
    EXPECT_EQ(laengstes_wort(h, 2, 2), 2);
}

TEST(TeileHerrsche, SummeUndVorkommen) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(summe_laengen(t, 0, 13), 77);
    EXPECT_EQ(summe_laengen(t, 13, 13), 14);
    text_t d = {"und", "x", "und", "Und", "und"};
    EXPECT_EQ(anzahl_vorkommen(d, "und", 0, 4), 3);
    EXPECT_EQ(anzahl_vorkommen(d, "und", 1, 3), 1);
    EXPECT_EQ(anzahl_vorkommen(d, "nd", 0, 4), 0);
}

TEST(TeileHerrsche, GleichlangLauf) {
    text_t t = read_words("beispiel.txt");
    EXPECT_EQ(laengster_gleichlang_lauf(t, 0, 13), 2);       // "wenig Platz"
    text_t m = {"a", "bb", "ccc", "ddd", "eee", "fff", "g", "h"};
    EXPECT_EQ(laengster_gleichlang_lauf(m, 0, 7), 4);        // liegt UEBER der Mitte
    text_t e = {"a", "b", "c"};
    EXPECT_EQ(laengster_gleichlang_lauf(e, 0, 2), 3);
    EXPECT_EQ(laengster_gleichlang_lauf(e, 1, 1), 1);
    text_t r = {"aa", "b", "cc", "dd"};
    EXPECT_EQ(laengster_gleichlang_lauf(r, 0, 3), 2);        // am rechten Rand
}

TEST(TeileHerrsche, KostenZeile) {
    text_t t = read_words("beispiel.txt");
    zeilen_t z = umbruch(t, 29);                              // {0, 5, 10, 13}
    EXPECT_EQ(kosten_zeile(t, z, 29, 0), 4);
    EXPECT_EQ(kosten_zeile(t, z, 29, 1), 0);
    EXPECT_EQ(kosten_zeile(t, z, 29, 2), 144);
    EXPECT_EQ(kosten_zeile(t, z, 29, 3), 0);                 // letzte Zeile
}

TEST(TeileHerrsche, TeuersteZeile) {
    text_t t = read_words("beispiel.txt");
    zeilen_t z = umbruch(t, 29);
    EXPECT_EQ(teuerste_zeile(t, z, 29, 0, 3), 2);
    EXPECT_EQ(teuerste_zeile(t, z, 29, 0, 1), 0);
    EXPECT_EQ(teuerste_zeile(t, z, 29, 3, 3), 3);
    text_t g = {"ab", "cd", "ef", "gh"};                     // jede Zeile ein Wort, alle gleich teuer
    zeilen_t zg = {0, 1, 2, 3};
    EXPECT_EQ(teuerste_zeile(g, zg, 5, 0, 3), 0);            // Gleichstand: kleinster Index
    EXPECT_EQ(teuerste_zeile(g, zg, 5, 1, 3), 1);
}

TEST(TeileHerrsche, ZufallGegenSchleife) {
    mt19937 rng(4711);
    for (int k = 0; k < 300; k++) {
        text_t t = zufall(rng, 1 + k % 40, 4);
        int n = t.size();
        int soll_idx = 0; long soll_sum = 0; int soll_lauf = 1, lauf = 1;
        for (int i = 0; i < n; i++) {
            if (t[i].size() > t[soll_idx].size()) soll_idx = i;
            soll_sum += t[i].size();
            if (i > 0) { lauf = (t[i].size() == t[i - 1].size()) ? lauf + 1 : 1; if (lauf > soll_lauf) soll_lauf = lauf; }
        }
        EXPECT_EQ(laengstes_wort(t, 0, n - 1), soll_idx);
        EXPECT_EQ(summe_laengen(t, 0, n - 1), soll_sum);
        EXPECT_EQ(laengster_gleichlang_lauf(t, 0, n - 1), soll_lauf);
    }
}

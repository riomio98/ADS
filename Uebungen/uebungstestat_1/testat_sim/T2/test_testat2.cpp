#include "alltest.h"
#include "testat2.h"
#include "common.h"
#include "pbma.h"
#include <stdexcept>

using namespace std;

TEST(Setzen, Zeile) {
    text_t t = {"Ein", "guter", "Umbruch"};
    EXPECT_EQ(zeile(t, 0, 3), "Ein guter Umbruch");          // kein Leerzeichen am Ende!
    EXPECT_EQ(zeile(t, 1, 2), "guter");
    EXPECT_EQ(zeile(t, 0, 0), "");
}

TEST(Setzen, Rechtsbuendig) {
    text_t t = {"Ein", "guter", "Umbruch"};
    EXPECT_EQ(rechtsbuendig(t, 0, 2, 12), "   Ein guter");
    EXPECT_EQ(rechtsbuendig(t, 0, 2, 9), "Ein guter");      // genau b: nichts auffuellen
    EXPECT_EQ(rechtsbuendig(t, 0, 2, 9).size(), 9u);
    EXPECT_THROW(rechtsbuendig(t, 0, 3, 16), std::invalid_argument);
}

TEST(Setzen, Blocksatz) {
    EXPECT_EQ(blocksatz({"a", "b", "c", "d"}, 0, 4, 10), "a  b  c  d");
    EXPECT_EQ(blocksatz({"a", "b", "c", "d"}, 0, 4, 11), "a   b  c  d");    // vordere Luecke zuerst
    EXPECT_EQ(blocksatz({"a", "b", "c", "d"}, 0, 4, 12), "a   b   c  d");
    EXPECT_EQ(blocksatz({"a", "b", "c", "d"}, 0, 4, 7), "a b c d");         // passt genau
    EXPECT_EQ(blocksatz({"ab"}, 0, 1, 6), "ab");                            // ein Wort: nicht auffuellen
    EXPECT_THROW(blocksatz({"abc", "def"}, 0, 2, 6), std::invalid_argument);
}

TEST(Setzen, BlocksatzBreite) {
    text_t t = read_words("beispiel.txt");
    zeilen_t z = umbruch(t, 29);
    for (size_t k = 0; k + 1 < z.size(); k++) {               // jede Zeile ausser der letzten wird genau b breit
        string s = blocksatz(t, z[k], z[k + 1], 29);
        EXPECT_EQ(s.size(), 29u) << "Zeile " << k;
        EXPECT_NE(s.front(), ' ');
        EXPECT_NE(s.back(), ' ');
    }
}

TEST(Setzen, SetzeLinks) {
    text_t t = read_words("beispiel.txt");
    vector<string> soll = {"Ein guter Umbruch laesst am", "rechten Rand wenig Platz frei", "und braucht keine", "Silbentrennung"};
    EXPECT_EQ(setze(t, umbruch(t, 29), 29, 'l'), soll);
}

TEST(Setzen, SetzeRechts) {
    text_t t = read_words("beispiel.txt");
    vector<string> soll = {"  Ein guter Umbruch laesst am", "rechten Rand wenig Platz frei", "            und braucht keine", "               Silbentrennung"};
    EXPECT_EQ(setze(t, umbruch(t, 29), 29, 'r'), soll);       // auch die letzte Zeile rechtsbuendig
}

TEST(Setzen, SetzeBlock) {
    text_t t = read_words("beispiel.txt");
    vector<string> soll = {"Ein  guter  Umbruch laesst am", "rechten Rand wenig Platz frei", "und       braucht       keine", "Silbentrennung"};
    EXPECT_EQ(setze(t, umbruch(t, 29), 29, 'b'), soll);       // letzte Zeile linksbuendig, ohne Auffuellen
}

TEST(Setzen, SetzeRand) {
    text_t leer;
    EXPECT_TRUE(setze(leer, umbruch(leer, 10), 10, 'b').empty());
    text_t eins = {"Hallo"};
    EXPECT_EQ(setze(eins, {0}, 10, 'b'), vector<string>{"Hallo"});
    EXPECT_EQ(setze(eins, {0}, 10, 'r'), vector<string>{"     Hallo"});
    EXPECT_THROW(setze(eins, {0}, 10, 'x'), std::invalid_argument);
    EXPECT_THROW(setze(eins, {0}, 10, 'L'), std::invalid_argument);   // Gross/Klein zaehlt
}

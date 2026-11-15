#include "alltest.h"
#include "testat6.h"
#include "pbma.h"
#include <chrono>
#include <random>
#include <stdexcept>

using namespace std;

TEST(MergeSort, MergeAllein) {
    text_t a = {"x", "bb", "cccc", "a", "dd", "eee"};        // [0..2] und [3..5] sind schon sortiert
    merge_laenge(a, 0, 2, 5);
    EXPECT_EQ(a, (text_t{"x", "a", "bb", "dd", "eee", "cccc"}));   // "x" vor "a": stabil!
    text_t b = {"zz", "q", "r", "s"};                        // nur [1..3] mischen, Rest bleibt
    merge_laenge(b, 1, 1, 3);
    EXPECT_EQ(b, (text_t{"zz", "q", "r", "s"}));
}

TEST(MergeSort, Sortieren) {
    text_t a = {"ccc", "a", "bb", "ddd", "e", "ff", "g"};
    mergesort_laenge(a, 0, 6);
    EXPECT_EQ(a, (text_t{"a", "e", "g", "bb", "ff", "ccc", "ddd"}));
    text_t teil = {"ccc", "a", "bb", "ddd", "e"};
    mergesort_laenge(teil, 1, 3);                            // nur der Bereich [1..3]
    EXPECT_EQ(teil, (text_t{"ccc", "a", "bb", "ddd", "e"}));
    mergesort_laenge(teil, 0, 4);
    EXPECT_EQ(teil, (text_t{"a", "e", "bb", "ccc", "ddd"}));
}

TEST(MergeSort, Rand) {
    text_t leer;
    EXPECT_TRUE(sortiert_nach_laenge(leer).empty());
    text_t eins = {"x"};
    EXPECT_EQ(sortiert_nach_laenge(eins), eins);
}

TEST(MergeSort, KopieUndStabil) {
    const text_t t = read_words("beispiel.txt");
    text_t s = sortiert_nach_laenge(t);
    EXPECT_EQ(t[0], "Ein");                                  // Original unveraendert
    EXPECT_EQ(s, (text_t{"am", "Ein", "und", "Rand", "frei", "guter", "wenig", "Platz", "keine", "laesst", "Umbruch", "rechten", "braucht", "Silbentrennung"}));
}

TEST(MergeSort, KLaengste) {
    text_t t = {"ccc", "a", "bb", "ddd", "e", "ff", "g"};
    EXPECT_EQ(k_laengste(t, 4), (text_t{"ccc", "ddd", "bb", "ff"}));    // Gleichstand: Textreihenfolge
    EXPECT_EQ(k_laengste(t, 1), (text_t{"ccc"}));
    EXPECT_EQ(k_laengste(t, 3), (text_t{"ccc", "ddd", "bb"}));
    EXPECT_EQ(k_laengste(t, 0), text_t{});
    EXPECT_EQ(k_laengste(t, 99).size(), 7u);                 // mehr als vorhanden: alle
    EXPECT_EQ(k_laengste(t, 99).back(), "g");
    EXPECT_THROW(k_laengste(t, -1), std::invalid_argument);
}

TEST(MergeSort, SchnellUndStabil) {
    // O(n^2)-Verfahren sind hier zu langsam.
    mt19937 rng(5);
    uniform_int_distribution<int> len(1, 12);
    text_t t;
    for (int i = 0; i < 200000; i++) t.push_back(string(len(rng), 'a') + to_string(i));   // Endung = Original-Position
    auto start = chrono::steady_clock::now();
    text_t s = sortiert_nach_laenge(t);
    auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
    EXPECT_LT(ms, 5000) << "Sortieren brauchte " << ms << " ms";
    ASSERT_EQ(s.size(), t.size());
    for (size_t i = 1; i < s.size(); i++) {
        ASSERT_LE(s[i - 1].size(), s[i].size()) << "bei i = " << i;
        if (s[i - 1].size() == s[i].size()) {                // gleich lang: Original-Reihenfolge erhalten?
            int p1 = stoi(s[i - 1].substr(s[i - 1].find_first_of("0123456789")));
            int p2 = stoi(s[i].substr(s[i].find_first_of("0123456789")));
            ASSERT_LT(p1, p2) << "nicht stabil bei i = " << i;
        }
    }
}

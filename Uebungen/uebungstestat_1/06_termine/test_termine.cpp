#include "alltest.h"
#include "termine.h"

using namespace std;

TEST(termine, standard) {
    vector<Termin> t = {
        {1, 3}, {2, 5}, {3, 6}, {6, 8}
    };

    EXPECT_EQ(max_termine_rekursiv(t), 3);
}

TEST(termine, ueberlappungen) {
    vector<Termin> t = {
        {0, 2}, {1, 3}, {2, 4},
        {3, 5}, {4, 6}
    };

    EXPECT_EQ(max_termine_rekursiv(t), 3);
}

TEST(termine, grenzfaelle) {
    vector<Termin> leer;
    EXPECT_EQ(max_termine_rekursiv(leer), 0);

    vector<Termin> einzeln = {{2, 7}};
    EXPECT_EQ(max_termine_rekursiv(einzeln), 1);

    vector<Termin> direkt = {
        {1, 2}, {2, 3}, {3, 4}
    };
    EXPECT_EQ(max_termine_rekursiv(direkt), 3);
}

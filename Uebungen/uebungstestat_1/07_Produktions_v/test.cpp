/*
 * test.cpp
 *
 *  Created on: 16.11.2026
 *      Author: n3034770
 */


#include "main.cpp"

TEST(Geschwindigkeit, Standard) {
    EXPECT_EQ(min_geschwindigkeit({3, 6, 7, 11}, 8), 4);
    EXPECT_EQ(min_geschwindigkeit({3, 6, 7, 11}, 6), 6);
    EXPECT_EQ(min_geschwindigkeit({3, 6, 7, 11}, 27), 1);
}

TEST(Geschwindigkeit, Grenzen) {
    EXPECT_EQ(min_geschwindigkeit({5}, 1), 5);
    EXPECT_EQ(min_geschwindigkeit({5}, 2), 3);
    EXPECT_EQ(min_geschwindigkeit({1, 1, 1}, 3), 1);
}

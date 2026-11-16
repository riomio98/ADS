/*
 * main.cpp
 *
 *  Created on: 15.11.2026
 *      Author: n3034770
 */

#include "alltest.h"
#include "common.h"
#include "pbma.h"

using namespace std;

TEST(ZeilenbreiteRek, Basisfaelle) {
    EXPECT_EQ(zeilenbreite_rek({}, 0, 0), 0);
    EXPECT_EQ(zeilenbreite_rek({"Hallo"}, 0, 1), 5);
}

TEST(ZeilenbreiteRek, MehrereWoerter) {
    vector<string> t = {"aa", "bbb", "c", "dd"};

    EXPECT_EQ(zeilenbreite_rek(t, 0, 4), 11);
    EXPECT_EQ(zeilenbreite_rek(t, 0, 2), 6);
    EXPECT_EQ(zeilenbreite_rek(t, 2, 4), 4);
}

TEST(ZeilenbreiteRek, Teilbereiche) {
    vector<string> t = {"aa", "bbb", "c", "dd", "eee"};

    EXPECT_EQ(zeilenbreite_rek(t, 1, 3), 5);
    EXPECT_EQ(zeilenbreite_rek(t, 2, 2), 0);
    EXPECT_EQ(zeilenbreite_rek(t, 0, 5), 15);
}



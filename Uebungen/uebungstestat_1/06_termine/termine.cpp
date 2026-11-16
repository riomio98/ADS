/*
 * termine.cpp
 *
 *  Created on: 15.11.2026
 *      Author: n3034770
 */




#include <vector>
#include <climits>
#include "termine.h"
using namespace std;



int max_termine_iterativ(const vector<Termin>& termine)
{
    int anzahl = 0;
    int letztes_ende = INT_MIN;

    for (size_t i = 0; i < termine.size(); ++i) {
        if (termine[i].start >= letztes_ende) {
            ++anzahl;
            letztes_ende = termine[i].ende;
        }
    }

    return anzahl;
}




int helper(const vector<Termin>& termine,
           size_t idx,
           int res,
           int letztes_ende)
{
    if (idx >= termine.size()) {
        return res;
    }

    if (termine[idx].start >= letztes_ende) {
        ++res;
        letztes_ende = termine[idx].ende;
    }

    return helper(termine, idx + 1, res, letztes_ende);
}

int max_termine_rekursiv(const vector<Termin>& termine)
{
	if(termine.empty())
	{
		return 0;
	}
	int res = 1;
	size_t idx = 1;
	int letztes_ende = termine[0].ende;
    return helper(termine, idx, res, letztes_ende);
}

/*
 * kleinste.cpp
 *
 *  Created on: 26.09.2026
 *      Author: n3034770
 */
#include <iostream>
#include <vector>
//#include <limits>
#include <climits>

using namespace std;


int kleinste(const vector<int>& a)
{
	//int min = numeric_limits<int>::max();
	int min = INT_MAX;

	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] < min)
		{
			min = a[i];
		}
	}

	return min;
}




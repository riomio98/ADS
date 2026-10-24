/*
 * main.cpp
 *
 *  Created on: 17.10.2026
 *      Author: n3034770
 */
#include "ms.h"
#include <iostream>

using namespace std;




int main()
{

	vector<int> a = {1, 4, 7, 10, 10, 12};
	vector<int> b = {2, 3, 7, 12, 30, 50, 100, 1000, 10000};
	vector<int> c(a.size()+b.size());

	c = merge_sorted(a,b);
	dedup(c);



	return 0;
}

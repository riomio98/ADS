/*
 * bigint.cpp
 *
 *  Created on: 06.11.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
#include "pbma.h"
#include <iomanip>

using namespace std;



BigInt pm(BigInt x)
{
	if(x == 0)
	{
		return 0;
	}
	if(x < 0)
	{
		x++;
		return pm(x) + 1;
	}
	if(x > 0)
	{
		x--;
		return pm(x) -1;
	}
	return x;
}

BigInt add(BigInt x, BigInt y) {

	if (x == 0) {
		return y;
	}
	if (x > 0) {
		x--;
		y++;
		return add(x, y);
	}
	if (x < 0) {
		x++;
		y--;
		return add(x, y);
	}
	return y;
}

BigInt mult(BigInt x, BigInt y)
{

	if(x == 0)
	{
		return 0;
	}
	if(x > 0)
	{
		x--;
		return add(y,mult(x,y));
	}
	if(x < 0)
	{
		return mult(pm(x), pm(y));
	}


	return y;

}

int main() {
	BigInt x = -1;
	BigInt y = 4;

	vector<int> v = {-10,-20,-30,-40,-50,-60,-70,-80,-90,-100,10,20,30,40,50,60,70,80,90,100};

	Timer timer1;
	int cnt = 0;
	for (size_t i = 0; i < v.size(); ++i) {


		for(size_t j = i; j < v.size(); ++j)
		{
			cout << ++cnt  << endl;
			cout  << v[i] << " + " << v[j] << " = " << add(v[i], v[j]) << endl;
			cout  << v[i] << " * "  << v[j] << " = " << mult(v[i], v[j]) << endl;
		}

	}
	cout << timer1.human_measure() << endl;

	return 0;
}

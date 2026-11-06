/*
 * mehrfach.cpp
 *
 *  Created on: 06.11.2026
 *      Author: n3034770
 */
#include "pbma.h"
#include <iostream>
#include <stdexcept>
using namespace std;

BigInt power_a_it(BigInt n, int p)
{
	BigInt prod = 1;
	for(int i = 0; i < p; i++)
	{
		prod*= n;
	}
	return prod;
}

BigInt power_a_rec(BigInt n, int p)
{
	if(p < 0)
	{
		throw runtime_error("not valid for this formula");
	}
	if(p == 0)
	{
		return 1;
	}

	return n * power_a_rec(n, p-1);
}

BigInt power_a_endrec(BigInt n, int p, BigInt acc)
{
	if(p < 0)
	{
		throw runtime_error("not valid for this formula");
	}
	if(p == 0)
	{
		return acc;
	}


	return power_a_endrec(n, p-1, acc *n);
}

BigInt power_b(BigInt n, int p)
{
	if(p < 0)
	{
		throw runtime_error("not valid for this formula");
	}
	if(p == 0)
	{
		return 1;
	}
	BigInt power = power_b(n, p/2);
	if(p >= 1 && p % 2 != 0)
	{

		return n * power * power;
	}

	return power * power;
}


int main()
{

//	cout << power_a_endrec(2,3,1) << endl;
//	cout << power_a_it(2,3) << endl;
//	cout << power_a_rec(2,3) << endl;
//	cout << power_b(2,3) << endl;

	Timer timer;
	for (BigInt n = 1; n <= 4; ++n) {
		for(int p = 0; p <= 1024; ++p)
		{
			power_a_endrec(n,p,1);
		}
	}
	cout << "End-Rekursiv: " << timer.human_measure() << endl;

	timer.restart();
	for (BigInt n = 1; n <= 4; ++n) {
		for(int p = 0; p <= 1024; ++p)
		{
			power_a_it(n,p);
		}
	}
	cout << "Iterativ: " << timer.human_measure() << endl;


	timer.restart();
	for (BigInt n = 1; n <= 4; ++n) {
		for(int p = 0; p <= 1024; ++p)
		{
			power_a_rec(n,p);
		}
	}
	cout << "Rekursiv: " << timer.human_measure() << endl;

	timer.restart();
	for (BigInt n = 1; n <= 4; ++n) {
		for(int p = 0; p <= 1024; ++p)
		{
			power_b(n,p);
		}
	}
	cout << "power_b: " << timer.human_measure() << endl;
	return 0;
}


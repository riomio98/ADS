/*
 * main.cpp
 *
 *  Created on: 24.10.2026
 *      Author: n3034770
 */

#include <iostream>
using namespace std;

int rec_sum(int n)
{
	if(n == 0)
	{
		return 0	;
	}
	return n + rec_sum(n-1);
}

int rec_quadrat(int a, int n)
{
	if(n == 0)
	{
		return 1;
	}
	int half = rec_quadrat(a, n/2);
	if(n % 2 == 0)
	{

		return half * half;
	}
	else {
		return a * half * half;
	}

}

int fib(int n)
{
	if(n == 1)
	{
		return 1;
	}
	if(n == 0)
	{
		return 0;
	}

	return fib(n-1) + fib(n-2);
}

int main()
{

	int a;
	cin >> a;

	int n;
	cin >> n;


	int res = fib(n);
	cout << res << endl;




	return 0;
}



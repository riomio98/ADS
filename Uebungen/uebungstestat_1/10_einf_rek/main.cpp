/*

 * main.cpp

 *

 *  Created on: 17.11.2026

 *      Author: n3034770

 */

#include <iostream>

#include <vector>

#include <stdexcept>


using namespace std;

int anstiege_rek(const vector<int>& v, size_t i)

{

	if(i >= v.size())
	{
		return 0;
	}
	if(v[i-1] < v[i])
	{
		return 1 + anstiege_rek(v,i+1);
	}

	return anstiege_rek(v,i+1);

}



int negative_summe_rek(const vector<int>& v, size_t i, int summe)
{
	if(i >= v.size())
	{
		return summe;
	}
	if(v[i] < 0)
	{
		summe += abs(v[i]);
	}
	return negative_summe_rek(v,i+1, summe);
}

int main()

{

	vector<int> v = {3, 7, 2, 5, 5, 9};
	cout << anstiege_rek(v,1) << endl;

	vector<int> a = {4, -2, 5, -7, 0, -3};
	cout << negative_summe_rek(a,0,0) << endl;

	return 0;

}

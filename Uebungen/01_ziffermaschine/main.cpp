/*
 * main.cpp
 *
 *  Created on: 14.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>

using namespace std;


int transform(int n, int& anz, int& max)
{
	vector<int> vec_rest;
	int rest;
	int sum = 0;
	
	
	for(int i = n; i>0; i/=10)
	{
		rest = i % 10;
		if(rest > max)
		{
			max = rest;
		}
		if(rest % 2 != 0)
		{
			sum -= rest; 
		}
		else {
			sum += rest;
		}
		anz++;
		
	}
	return sum;
}

int main(){
	
	int n = 58342;
	if(n < 0)
	{
		return 1;
	}
	int anz = 0;
	int max = 0;
	
	int y = transform(n, anz, max);
	
	cout << "Anzahl Summanden: " << anz << endl;
	cout << "Max Summand: " << max << endl;
	cout << "Summe: " << y << endl;
	
	return 0;
	
}

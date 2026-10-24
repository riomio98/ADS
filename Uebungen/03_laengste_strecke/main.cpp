/*
 * main.cpp
 *
 *  Created on: 14.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
#include <string>
#include "pbma.h"

using namespace std;


int func(vector<int>& v)
{
	int len = 0;
	for(size_t i = 0; i < v.size()-1; i++)
	{
		if(v[i] < v[i+1])
		{
			len++;
		}
		else
		{
			len = 0;
		}
	}
	return len;
}

int main()
{

	string filename = "zahlen.dat";


	vector<int> v = read_ints(filename);

	func(v);




	return 0;
}


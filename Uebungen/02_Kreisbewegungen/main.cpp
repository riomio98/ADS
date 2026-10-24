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
#include "cmath"
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
	args_t args(argc, argv);
	
	int n = 8;//args.int_pos(0);
	int start = 6;//args.int_pos(1);

	vector<int> vec = {3, -5, 12, -2};
	int pos = start;

	cout << "Start: " << start
	     << "   n: " << n << endl;

	cout << left
	     << setw(10) << "Schritt"
	     << setw(12) << "Bewegung"
	     << setw(10) << "Position"
	     << endl;

	cout << string(32, '-') << endl;


	for(size_t j = 0; j < vec.size(); j++)
	{
		pos += vec[j];
		pos = pos % n;
		if(pos < 0)
		{
			pos = n + pos;
		}
		cout << left
		     << setw(10) << j + 1
		     << setw(12) << vec[j]
		     << setw(10) << pos
		     << endl;
	}




	return 0;
}

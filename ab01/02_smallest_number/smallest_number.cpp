/*
 * smallest_number.cpp
 *
 *  Created on: 26.09.2026
 *      Author: n3034770
 */

#include <fstream>
#include "pbma.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int getSmallest(const vector<int>& numbers)
{
	if(numbers.empty())
	{
		cout << "ERROR: Numbers are empty" << endl;
	}

	int smallest = numbers[0];
	for(int i = 1; i < numbers.size(); i++) // kann bei 1 starten wenn smallest = numbers[0] gesetzt wurde
	{
		if(numbers[i] < smallest)
		{
			smallest = numbers[i];
		}

	}
	return smallest;
}

int main(int argc, const char* argv[])
{
	args_t args(argc, argv);

	string file_name = args.pos(0,"zahlen.dat");

	vector<int> numbers = read_ints(file_name);

	cout << "the smallest number is: "<< getSmallest(numbers) << endl;


	return 0;
}





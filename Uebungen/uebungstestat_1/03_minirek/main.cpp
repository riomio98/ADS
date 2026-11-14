/*
 * main.cpp
 *
 *  Created on: 12.11.2026
 *      Author: n3034770
 */

#include <vector>
#include <string>
#include <iostream>
#include "pbma.h"

using namespace std;


int zaehle(const vector<string>& text, size_t idx)
{
	int num = 0;
	if(idx == text.size())
	{
		return 0;
	}
	if(text[idx].size() > 5)
	{
		num++;
		num += zaehle(text, idx+1);
	}
	else if(text[idx].size() <= 5)
	{
		num += zaehle(text, idx+1);
	}

	return num;
}


int main(int argc, const char* argsv[])
{

	string fn = "test.txt";
	vector<string> v = read_words(fn);

	cout << zaehle(v,0) << endl;


	return 0;
}



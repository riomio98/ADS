/*
 * spalte.cpp
 *
 *  Created on: 30.10.2026
 *      Author: n3034770
 */
#include "pbma.h"
#include "common.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	args_t args(argc, argv);

	string file_name = args.pos(0, "beispiel.txt");
	vector<string> text = read_words(file_name);
	// size prüfen ?

	int b = 40;
	bool set_b = args.flag("w");
	bool set_cost = args.flag("z");

	if(args.has_option("w"))
	{
		b = args.int_option("w");
	}

	if(set_cost)
	{
		//todo add format
	}
	b = 10;

	vector<string> test = {"ich", "bin", "ein", "student"};
	vector<int> zahlen = umbruch(test, b);
	for(size_t i = 0; i < zahlen.size(); i++)
	{
		cout << zahlen[i] << endl;
	}



	return 0;
}




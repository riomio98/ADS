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

	int b = 40;
	bool format_cost = args.flag("z");

	if(args.has_option("w"))
	{
		b = args.int_option("w");
		if (b <= 0)
		{
		    throw runtime_error("Spaltenbreite muss positiv sein");
		}
	}




	vector<int> zeilen = umbruch(text, b);
	long cost = gesamtkosten(text, zeilen, b);
	print_umbruch(text, zeilen, cost, format_cost, b);




	return 0;
}




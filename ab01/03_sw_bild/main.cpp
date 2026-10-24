/*
 * main.cpp
 *
 *  Created on: 26.09.2026
 *      Author: n3034770
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "pbma.h"

using namespace std;

void convertToSw(vector<int>& v_bild, const int V, const int s_scaled)
{
	for(size_t i = 3; i < v_bild.size(); i++)
	{
		if(v_bild[i] < s_scaled)
		{
			v_bild[i] = 0;
		}
		else
		{
			v_bild[i] = V;
		}
	}
}

int main(int argc, const char* argv[])
{
	args_t args(argc, argv);

	string a_pgm = args.pos(0,"lena.pgm");
	string out_pgm = args.pos(1, "out.pgm");
	int s = args.int_pos(2, 50);

	vector<int> v_bild = read_pgm(a_pgm);

	//const int b = v_bild[0]; // erstes element: Breite
	//const int h = v_bild[1]; // zweites Element: Höhe
	const int V = v_bild[2]; // drittes Element: Max. Helligkeit
	const int s_scaled = (s/100.0) * V; // Threshold in prozent auf max Helligkeit skaliert

	convertToSw(v_bild, V, s_scaled);

	save_pgm(out_pgm, v_bild);


	return 0;
}



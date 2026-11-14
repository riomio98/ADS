/*
 * main.cpp
 *
 *  Created on: 13.11.2026
 *      Author: n3034770
 */


#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <iostream>
#include "pbma.h"

using namespace std;


struct Res{
	size_t start_idx;
	size_t end_idx;
	size_t cnt_days = 0;
	int sum_bes = 0;

};


vector<Res> calc_strong_days(vector<int>& bes)
{
	vector<Res> res;


	for(size_t i = 0; i < bes.size(); i++)
	{
		Res r;
		if(bes[i] >= 100)
		{
			size_t idx = i;
			while(idx < bes.size() && bes[idx] >= 100)
			{
				r.sum_bes += bes[idx];
				r.cnt_days++;
				idx++;

			}
			r.start_idx = i;
			i = i + r.cnt_days-1;
			r.end_idx = i;
			res.push_back(r);
		}
	}
	return res;
}


int main()
{

	string fname = "besucher.dat";
	vector<int> besucher = read_ints(fname);
	calc_strong_days(besucher);






	return 0;
}


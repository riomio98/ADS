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

void sort(vector<Res>& res)
{

	for(size_t i = 0; i < res.size(); i++)
	{
		for(size_t j= i+1; j < res.size(); j++)
		{
			if(res[i].sum_bes < res[j].sum_bes)
			{
				Res tmp = res[i];
				res[i] = res[j];
				res[j] = tmp;
			}
			else if(res[i].sum_bes == res[j].sum_bes)
			{
				if(res[i].start_idx > res[j].start_idx)
				{
					Res tmp = res[i];
					res[i] = res[j];
					res[j] = tmp;
				}
			}
		}
	}
}

int sum_max(vector<Res>& res)
{
	if(res.empty())
		return 0;
	size_t idx = 0;
	for(size_t i = 0; i < res.size(); i++)
	{
		if(res[idx].sum_bes < res[i].sum_bes)
		{
			idx = i;
		}
	}
	return res[idx].sum_bes;

}

void print(vector<Res>& res)
{
	for(size_t i = 0; i < res.size(); ++i)
	{
		cout << "Zeitraum " << i <<": Start=" << res[i].start_idx << ", Ende=" << res[i].end_idx
				<< ", Tage="<< res[i].cnt_days <<  ", Besucher=" << res[i].sum_bes << endl;
	}
	cout << endl;
	cout << "Anzahl Zeiträume: " << res.size() << endl;
	cout << "Groesste Besucherzahl: " << sum_max(res) << endl;
}


int main()
{

	string fname = "besucher3.dat";
	vector<int> besucher = read_ints(fname);
	vector<Res> res  = calc_strong_days(besucher);
	sort(res);
	print(res);


	return 0;
}


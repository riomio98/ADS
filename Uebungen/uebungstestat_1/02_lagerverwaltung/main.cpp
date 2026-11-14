/*
 * main.cpp
 *
 *  Created on: 10.11.2026
 *      Author: n3034770
 */


#include <string>
#include <vector>
#include "pbma.h"
#include <stdexcept>
#include <iostream>
using namespace std;

struct Ware{
	size_t nr;
	int qt;
};

vector<Ware> convert(const vector<int>& v)
{
	vector<Ware> waren;
	for(size_t i = 1; i < v.size(); i+=2)
	{
		Ware w;
		w.nr = v[i-1];
		w.qt = v[i];
		waren.push_back(w);
	}

	return waren;
}


void check(const vector<int>& v)
{
	if(v.size() % 2 != 0)
	{
		throw runtime_error("Eingabe Unvollstaendig");
	}
	for(size_t i = 0; i < v.size(); i+=2)
	{
		if(v[i] <= 0)
		{
			throw runtime_error("Artikelnummer nicht Positiv");
		}
	}
}

size_t is_in_res(const vector<Ware>& res, size_t nr)
{
	for(size_t i = 0; i < res.size(); i++)
	{
		if(res[i].nr == nr)
		{
			return i;
		}
	}
	return res.size();
}


vector<Ware> endbestand(const vector<Ware>& w)
{
	vector<Ware> lager;
	if(!w.empty())
	{
		if(w[0].qt < 0)
		{
			throw runtime_error("negativer Warenbestand");
		}
		lager.push_back(w[0]);
	}
	for(size_t i = 1; i < w.size(); i++)
	{
		size_t idx = is_in_res(lager, w[i].nr);
		if(idx != lager.size())
		{
			lager[idx].qt += w[i].qt;
			if(lager[idx].qt < 0)
			{
				throw runtime_error("negativer Warenbestand");
			}
		}
		else
		{
			if(w[i].qt < 0)
			{
				throw runtime_error("negativer Warenbestand");
			}
			lager.push_back(w[i]);
		}
	}

	return lager;
}

void sort(vector<Ware>& lager)
{


	for(size_t i = 0; i < lager.size(); i++)
	{
		size_t min = i;
		for(size_t j= i+1; j< lager.size(); j++)
		{
			if(lager[j].nr < lager[min].nr)
			{
				min = j;
			}
		}
		if(min!=i)
		{
			Ware tmp = lager[min];
			lager[min] = lager[i];
			lager[i] = tmp;
		}
	}
}

int gesamtbestand(vector<Ware>& lager)
{
	int ges = 0;
	for(size_t i = 0; i < lager.size(); i++)
	{
		ges += lager[i].qt;
	}


	 return ges;
}

void print(vector<Ware>& lager)
{
	for(size_t i = 0; i < lager.size(); i++)
	{
		cout << "Artikel " << lager[i].nr << ": " << lager[i].qt << endl;
 	}
	cout << "Artikelanzahl: " << lager.size() << endl;
	cout << "Gesamtbestand: " << gesamtbestand(lager) << endl;
}

int main()
{

	string fname = "lager.dat";
	vector<int> v = read_ints(fname);
	check(v);
	vector<Ware> w = convert(v);
	vector<Ware> lager = endbestand(w);
	sort(lager);
	print(lager);



	return 0;
}

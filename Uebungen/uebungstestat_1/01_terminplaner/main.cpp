/*
 * main.cpp
 *
 *  Created on: 10.11.2026
 *      Author: n3034770
 */


#include "pbma.h"
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

struct Termin
{
	int start;
	int end;
};

vector<Termin> convert(const vector<int>& v)
{
	vector<Termin> vt;
	for(size_t i = 1; i < v.size(); i += 2)
	{
		Termin t;
		t.start = v[i-1];
		t.end = v[i];
		if(t.start >= t.end)
		{
			throw runtime_error("no valid timerange");
		}
		vt.push_back(t);
	}
	return vt;
}

void sort_end(vector<Termin>& vt)
{
	for(size_t i = 0; i < vt.size(); i++)
	{
		size_t min = i;

		for(size_t j = i+1; j < vt.size(); j++)
		{
			if(vt[j].end < vt[min].end)
			{
				min = j;
			}
		}
		if(min != i)
		{
			Termin tmp = vt[i];
			vt[i] = vt[min];
			vt[min] = tmp;

		}
	}
}

vector<Termin> calendar(const vector<Termin>& vt)
{

	vector<Termin> labels;
	int last_end = vt[0].end;
	labels.push_back(vt[0]);
	for(size_t i = 1; i < vt.size(); i++)
	{
		if(vt[i].start >= last_end)
		{
			labels.push_back(vt[i]);
			last_end = vt[i].end;
		}
	}
	return labels;
}

int calc_sum_time(const vector<Termin>& labels)
{
	int sum_time = 0;
	for(size_t i = 0; i < labels.size(); i++)
	{
		sum_time += labels[i].end - labels[i].start;
	}
	return sum_time;
}


int main()
{

	string fname = "termine2.dat";
	vector<int> v = read_ints(fname);

	if (v.size() % 2 != 0)
	{
	    throw runtime_error("Unvollständige Terminpaare");
	}
	vector<Termin> vt = convert(v);
	sort_end(vt);
	vector<Termin> labels = calendar(vt);

	for(size_t i = 0; i < labels.size(); i++)
	{
		cout << "Termin "<< i+1 << ": " << labels[i].start << " - "<< labels[i].end << endl;
	}
	cout << "Termin Anzahl: " << labels.size() << ", Gesamtzeit: " << calc_sum_time(labels) << endl;




	return 0;
}



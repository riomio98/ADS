/*
 * main.cpp
 *
 *  Created on: 29.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
#include <string>
#include "pbma.h"


using namespace std;

int naive_sort(vector<int>& v)
{
	int max_sum = v[0] + v[1];
	for(size_t i = 0; i < v.size(); i++)
	{

		for(size_t j = i+1; j < v.size(); j++)
		{
			double sum = 0;
			for(size_t k = i; k < j+1; k++)
			{
				sum += v[k];
			}
			if(sum > max_sum)
			{
				max_sum = sum;
			}
		}
	}
	return max_sum;
}


int optim_sum(vector<int>& v)
{
	int max_sum = v[0] + v[1];
	for(size_t i = 0; i < v.size(); i++)
	{
		int sum = 0;

		for(size_t j = i; j < v.size(); j++)
		{
			sum += v[j];
			if(sum > max_sum)
			{
				max_sum = sum;
			}
		}
	}
	return max_sum;
}

int rec_optim(vector<int>& v,int li,int re)
{
	int m = li + (re-li)/2;
	if(li == re)
	{
		return v[li];
	}
	int left = rec_optim(v, li, m);
	int right = rec_optim(v, m+1, re);

	int sum = 0;
	int best_left;
	for(size_t i = li; i < m; i++)
	{
		sum += v[i];
		if(sum > best_left)
		{
			best_left = sum;
		}
	}
	sum = 0;
	int best_right;
	for(size_t i = m+1; i < re; i++)
	{
		sum += v[i];
		if(sum > best_right)
		{
			best_right = sum;
		}
	}
	if(best_left > best_right)
	{
		rec_optim(v,)
	}
 return best;
}


int main(int argc, char* argv[])
{
	args_t args(argc, argv);
	string fname = args.pos(0,"maxsub.dat");

	vector<int> v = read_ints(fname);

	if(v.size() < 2)
	{
		return 1;
	}

	//Timer timer1;
	//cout << naive_sort(v) << endl;
	//cout << timer1.human_measure() << endl;
	//Timer timer2;
	//cout << optim_sum(v) << endl;
	//cout << timer2.human_measure() << endl;


	vector<int> b = {-1,3,-3,3,-6, 15};
	int li = 0;
	int re = b.size();
	Timer timer3;
	rec_optim(b,li,re);




	return 0;
}





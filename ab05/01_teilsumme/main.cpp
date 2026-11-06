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

int naive_sum(vector<int>& v)
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
int max_case3(int l,int r, int sum_max)
{
	 int max = l;
	 if(r > max)
	 {
		 max = r;
	 }
	 if(sum_max > max)
	 {
		 max = sum_max;
	 }
	 return max;
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
	int mi = li + (re-li)/2;
	if(li == re)
	{
		return v[li];
	}
	int l = rec_optim(v, li, mi);
	int r = rec_optim(v, mi+1, re);

	int sum = 0;
	int max_l = v[mi];
	for(int  i = mi; i > li; i--)
	{
		sum += v[i];
		if(sum > max_l)
		{
			max_l = sum;
		}
	}

	sum = 0;
	int max_r = v[mi+1];
	for(int  i = mi+1; i < re; i++)
	{
		sum += v[i];
		if(sum > max_r)
		{
			max_r = sum;
		}
	}
	return max_case3(l,r, max_l + max_r);
}




int main(int argc, char* argv[])
{
	args_t args(argc, argv);
	string fname = args.pos(0,"maxsubverylarge.dat");

	vector<int> v = read_ints(fname);

	if(v.size() < 2)
	{
		return 1;
	}

//	Timer timer1;
//	cout << naive_sum(v) << endl;
//	cout << timer1.human_measure() << endl;

	Timer timer2;
	cout << optim_sum(v) << endl;
	cout << timer2.human_measure() << endl;

	int li = 0;
	int re = v.size();
	Timer timer3;
	cout << rec_optim(v,li,re) << endl;
	cout << timer3.human_measure() << endl;




	return 0;
}





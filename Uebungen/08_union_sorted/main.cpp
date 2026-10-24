/*
 * main.cpp
 *
 *  Created on: 18.10.2026
 *      Author: n3034770
 */

#include <vector>
#include "pbma.h"

using namespace std;

vector<int> union_sorted(vector<int>& a, vector<int>& b)
{
	if(a.empty() && b.empty())
	{
	    return {}; // für vectoren
	}
	vector<int> c(a.size()+b.size());
	size_t li = 0;
	size_t re = 0;
	size_t idx = 0;

	while(li < a.size() and re < b.size())
	{

		if(a[li] <= b[re])
		{
			c[idx] = a[li];
			li++;
			idx++;
		}
		else
		{
			c[idx] = b[re];
			re++;
			idx++;
		}
	}
	while(li < a.size())
	{
		c[idx] = a[li];
		li++;
		idx++;
	}
	while(re < b.size())
	{
		c[idx] = b[re];
		re++;
		idx++;
	}
	size_t j = 1;
	for(size_t i = 1; i < c.size(); i++) // 1,2,3,3,4,5
	{
		if(c[i] != c[i-1])
		{
			c[j] = c[i];
			j++;
		}
	}

	c.resize(j);
	return c;
}

int main()
{
	vector<int> a = {1,2,2,5,8};
	vector<int> b = {2,3,3,5,9};
	vector<int> c;


	int first_error;

	c = union_sorted(a,b);
	is_sorted(c, first_error);


	return 0;
}




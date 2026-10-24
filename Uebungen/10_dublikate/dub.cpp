/*
 * dub.cpp
 *
 *  Created on: 24.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>


using namespace std;

void rm_dublicates(vector<int>& v)
{
	size_t n = v.size();
	size_t i = 1;
	int idx = 0;
	while(i < n)
	{
		if(v[i] != v[idx])
		{
			idx++;
			v[idx] = v[i];
		}
		i++;
	}
	v.resize(idx);

}

void rm_zeros(vector<int>& v)
{
	size_t n = v.size();
	size_t i = 0;
	int idx = 0;
	while(i < n)
	{
		if(v[i] != 0)
		{

			v[idx] = v[i];
			idx++;
		}
		i++;
	}
	v.resize(idx);

}

int main()
{
	vector<int> a = {1,2,2,2,5,7,7,9};

	rm_dublicates(a);


	vector<int> b = {0,5,0,2,0,7,0,3};

	rm_zeros(b);


	return 0;
}



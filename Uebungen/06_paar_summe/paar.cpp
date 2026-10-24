/*
 * paar.cpp
 *
 *  Created on: 17.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
using namespace std;

bool has_pair_sum(const vector<int>& a, int x)
{
	int li = 0;
	int re = a.size()-1;

	while(li < re)
	{
		int sum = a[li] + a[re];
		if(sum == x)
		{
			return 1;
		}
		if(sum > x)
		{
			re--;
		}
		if(sum < x)
		{
			li++;
		}
	}
	return 0;

}

vector<int> intersect_sorted(const vector<int>& a, const vector<int>& b)
{
	vector<int> sm;

	size_t i = 0;
	size_t j = 0;

	while(i < a.size() and j < b.size())
	{
		if(a[i] < b[j])
		{
			i++;
		}
		else if(a[i] > b[j])
		{
			j++;
		}
		else
		{
			if(sm.empty() || sm.back() != a[i])
			{
				sm.push_back(a[i]);
			}
			i++;
			j++;
		}
	}
	return sm;

}


int main()
{

	vector<int> a = {1,2,3,6,7,35,66,88,222};
	int x = 41	;
	cout << has_pair_sum(a,x) << endl;;

	vector<int> b = {2, 2, 3, 4, 4, 8};
	vector<int> c = {1, 2, 2, 4, 7, 9};

	vector<int> d = intersect_sorted(b,c);
	for(size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << endl;
	}




	return 0;
}

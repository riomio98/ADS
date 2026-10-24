/*
 * main.cpp
 *
 *  Created on: 17.10.2026
 *      Author: n3034770
 */
#include <iostream>
#include <vector>


using namespace std;


int unique_values(vector<int>& v)
{
	int idx = 1;
	if(v.empty())
	{
		return 0;
	}
	for(size_t i = 1; i < v.size(); i++)
	{
		if(v[i-1] != v[i])
		{
			v[idx] = v[i];
			idx++;
		}
	}
	return  idx;
}


vector<int> run_lengths(const vector<int>& v)
{
	 vector<int> v_l;
	 int cnt = 1;
	 for(size_t i = 1; i< v.size(); i++)
	 {
		 if(v[i-1] == v[i])
		 {
			 cnt++;
		 }
		 else
		 {
			 v_l.push_back(cnt);
			 cnt = 1;
		 }
	 }
	 v_l.push_back(cnt);

	 return v_l;
}

int count_peaks(const vector<int>& v)
{
	if(v.size() < 3)
	{
		return 0;
	}
	int max = 0;
	for(size_t i = 1; i < v.size()-1; i++)
	{
		if(v[i] > v[i-1] and v[i] > v[i+1])
		{
			max++;
		}
	}
	return max;
}


int longest_equal_run(const vector<int>& v)
{
	int longest = 1;
	int max = 0;
	if(v.empty())
	{
		return 0;
	}
	for(size_t i = 1; i < v.size(); i++)
	{
		if(v[i] == v[i-1])
		{
			longest++;
		}
		else
		{
			if(longest > max)
			{
				max = longest;
				longest = 1;
			}
			longest = 1;
		}
	}
	if(longest > max)
	{
		max = longest;
	}
	return max;
}

int main()
{
	vector<int> v = {4,4,4,2,2,7,7,7,7,3};
	
	int n = longest_equal_run(v);
	
	cout << n << endl;
	
	return 0;
}



/*
 * main.cpp
 *
 *  Created on: 24.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
#include <stdexcept>


using namespace std;
int max_teil_sum( const vector<int>& a)
{
	int max = a[0];
	for(size_t i = 0; i< a.size(); i++)
	{
		int sum = 0;
		for(size_t j = i; j <  a.size(); j++)
		{
			sum += a[j];
			if(sum > max)
			{
				max = sum;
			}
		}
	}
	return max;
}

int max_diff(const vector<int>& a)
{

	size_t n = a.size();
	if(n < 2)
	{
		throw invalid_argument("vector has not enough elements");
	}
	int max_diff = a[1] - a[0];
	for(size_t i = 0; i < n-1; i++)
	{
		int diff = 0;
		for(size_t j = i+1; j < n; j++)
		{
			diff = a[j] - a[i];
			if(diff > max_diff)
			{
				max_diff = diff;
			}
		}
	}


	return max_diff;
}




int main()
{
	vector<int> a = {-2,4,-1,3,-5,2};
	int max = max_teil_sum(a);
	cout << max << endl;

	vector<int> b = {8, 3, 6, 2, 9, 5};
	max_diff(b);


	return 0;
}

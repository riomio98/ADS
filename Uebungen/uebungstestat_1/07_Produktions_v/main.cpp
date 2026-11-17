/*
 * main.cpp
 *
 *  Created on: 16.11.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
#include <stdexcept>



using namespace std;

long long ges_h(const vector<int>& v, int k)
{
	long long sum = 0;
	for (size_t i = 0; i < v.size(); ++i)
	{
		sum+= (v[i] + k - 1)/k;
	}
	return sum;
}

int max(const vector<int>& v)
{
	if(v.empty()){return 0;}
	int max = v[0];
	for (size_t i = 1; i < v.size(); ++i) {
		if(v[i] > max)
		{
			max = v[i];
		}
	}
	return max;
}


int min_geschwindigkeit(
    const vector<int>& v,
    int h
)
{
	int bis = max(v);
	int von = 1;
	int k;
	while(von < bis)
	{
		 k = von+(bis-von)/2;
		if(ges_h(v ,k) <= h)
		{
			bis = k;
		}
		else{
			von = k+1;
		}
	}
	return k;
}


int main()
{


	vector<int> v = {3, 6, 7, 11};
	int h = 8;
	cout << min_geschwindigkeit(v,h) << endl;
	return 0;
}



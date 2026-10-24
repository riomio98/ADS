/*
 * main.cpp
 *
 *  Created on: 24.10.2026
 *      Author: n3034770
 */
#include <vector>
#include <iostream>

using namespace std;


bool diff_search(const vector<int>& x, int d)
{
	size_t i = 0;
	size_t j = 1;

	while(j < x.size())
	{
		if(i == j)
		{
			j++;
		}
		int diff = x[j] - x[i];
		if(diff == d)
		{
			return true;
		}
		else if(diff < d)
		{
			j++;
		}
		else if(diff > d)
		{
			i++;
		}
	}
	return false;
}

int main(){


	vector<int> x = {1,3,4,7,9,13,18};
	int d;
	cin >> d;



	bool y = diff_search(x,d);
	if(y)
		cout << "true"<< endl;
	else
		cout << "false" << endl;


	return 0;
}

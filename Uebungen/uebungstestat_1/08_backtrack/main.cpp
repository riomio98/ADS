/*
 * main.cpp
 *
 *  Created on: 16.11.2026
 *      Author: n3034770
 */

#include <iostream>
#include <vector>

using namespace std;





bool zielsumme(const vector<int>& zahlen, int ziel,size_t i, int sum)
{
	if (sum == ziel)
	{
	    return true;
	}

	if(i == zahlen.size())
	{
		return false;
	}
	if(zahlen[i] + sum <= ziel)
	{
		if(zielsumme(zahlen, ziel, i+1, sum+zahlen[i]))
		{
			return true;
		}

	}
	return zielsumme(zahlen, ziel, i + 1, sum);
}


bool zielsumme(
    const vector<int>& zahlen,
    int ziel
)
{
	if(zahlen.size() > 20)
	{
		return false;
	}

	if(zahlen.empty())
	{
		if(ziel == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return zielsumme(zahlen,ziel,0,0);
}


int main()
{
	vector<int> v = {3, 5};
	int ziel = 5;
	zielsumme(v, ziel);




	return 0;
}

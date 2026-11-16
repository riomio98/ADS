/*
 * vzwechsel.cpp
 *
 *  Created on: 15.11.2026
 *      Author: n3034770
 */


#include <vector>
#include <string>
#include <iostream>

using namespace std;


int vzwechsel(vector<int>& v, int von, int bis)
{
	if(von >= bis-1)
	{
		return 0;
	}
	int mi = von + (bis-von)/2;

	int links = vzwechsel(v,von,mi);
	int rechts = vzwechsel(v,mi,bis);

	 if((v[mi-1] < 0 && v[mi] > 0) ||
			 (v[mi-1] > 0 && v[mi] < 0))
	 {
		 return 1 + links + rechts;
	 }

	return links + rechts;
}

int main()
{

vector<int> v = {2,-3,-5,4,-1};

cout << vzwechsel(v,0,5) << endl;


return 0;
}


/*
 * main.cpp
 *
 *  Created on: 23.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>

using namespace std;

void heapsort(vector<int>& vec)
{
	size_t root = 1;


	int min = vec[1];
	vec[1] = vec[vec.size()-1];
	vec.pop_back();


	while(root*2 < vec.size())
	{
		size_t li = root*2;
		size_t re = root*2+1;
		if(vec[re] < vec[li])
		{
			if(root < re)
			{
				int tmp = vec[re];
				vec[re] = vec[root];
				vec[root] = tmp;
			}
		}
		else if(vec[li] < vec[re])
		{
			if(vec[root] < vec[li])
			{
				vec[li] = vec[root];
			}
		}

	}


}


int main()
{
	vector<int> vec = {0, 17, 42, 33, 44, 47 , 88, 66, 49, 100, 58};
	cout << vec.size() << endl;
	heapsort(vec);

}

/*
 * main.cpp
 *
 *  Created on: 23.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
#include "pbma.h"

using namespace std;


void bubble_up(vector<int>& vec, vector<int>& heap)
{
	size_t n = vec.size();

	for(size_t j = 0; j < n; j++)
	{
		heap.push_back(vec[j]);

		size_t i = heap.size()-1;
		int vater = i/2;

		while(i > 1)
		{
			if(heap[vater] > heap[i])
			{
				swap(heap, vater, i);
				i = vater;
				vater = i/2;
			}
			else
			{
				break;
			}
		}

	}
}

void bubble_down(vector<int>& vec, vector<int>& heap)
{
	size_t j = 0;

	while(heap.size() > 1)
	{
		vec[j] = heap[1];
		size_t i = 1;

		heap[1] = heap[heap.size()-1];
		heap.pop_back();

		while(i*2 < heap.size())
		{
			size_t links = i*2;
			size_t re = i*2+1;
			size_t min = links;

			if(re < heap.size() and heap[re] < heap[links])
			{
				min = re;
			}
			if(heap[i] > heap[min])
			{
				swap(heap,i,min);
				i = min;
			}
			else {
				break;
			}
		}


		j++;
	}
}


void heapsort(vector<int>& vec, vector<int>& heap)
{

	bubble_up(vec,heap);
	bubble_down(vec,heap);


}


int main()
{
	vector<int> vec = create_randints(10,0,100);
	vector<int> heap = {0};
	heapsort(vec, heap);

}

/*
 * mysort.cpp
 *
 *  Created on: 16.10.2026
 *      Author: n3034770
 */
#include "pbma.h"
#include "mysort.h"
 
//MYSORT
 void mysort(std::vector<int>& numbers)
 {
	int max = numbers[0];
	int min = numbers[0];
	for(size_t i = 0; i < numbers.size(); i++)
	{
		if(max < numbers[i])
		{
			max = numbers[i];
		}
		if(min > numbers[i])
		{
			min = numbers[i];
		}
	}
	std::vector<int> counter(max -min+1, 0);
 	int zahl;
 	for(size_t i = 0; i < numbers.size(); i++)
 	{
 		zahl = numbers[i];
 		//todo forr negative numbers
 		counter[zahl-min]++;
 	}
 	int anz;
 	int idx = 0;
 	for(size_t i = 0; i < counter.size(); i++)
 	{
 		anz = counter[i];

 		while(anz > 0)
 		{
 			numbers[idx] = i+min;
 			idx++;
 			anz--;
 		}

 	}
 }

 
 
 //MERGESORT
 inline void MyCopy(std::vector<int> &a, std::vector<int> &b, size_t from, size_t to) {
 	for (size_t idx = from; idx < to; idx++) {
 		a[idx] = b[idx];
 	}
 }
 void Mergen(std::vector<int> &a, std::vector<int> &b, int start_links, int end_links,
 		int start_rechts, int end_rechts) {
 	size_t start = start_links;
 	size_t end = end_rechts;
 	size_t i = start_links;
 	while (start_links <= end_links and start_rechts <= end_rechts) {
 		if (a[start_links] <= a[start_rechts]) 
 		{
 			swap(b, i++, a, start_links++);
 		} 
 		else 
 		{
 			swap(b, i++, a, start_rechts++);
 		}
 	}
 	while (start_links <= end_links) {

 		swap(b, i++, a, start_links++);

 	}
 	while (start_rechts <= end_rechts) {
 		swap(b, i++, a, start_rechts++);
 	}
 	MyCopy(a, b, start, end + 1);
 }

 void MergeSort(std::vector<int> &a, std::vector<int> &b, int links, int rechts) {
 	if (links == rechts)
 		return;
 	size_t mitte = links + (rechts - links) / 2;
 	MergeSort(a, b, links, mitte);
 	MergeSort(a, b, mitte + 1, rechts);
 	Mergen(a, b, links, mitte, mitte + 1, rechts);
 }

 void MergeSort(std::vector<int> &a) {
 	int links = 0;
 	int rechts = a.size() - 1;
 	std::vector<int> b(a.size());
 	MergeSort(a, b, links, rechts);
 }

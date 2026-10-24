/*
 * sort_main.cpp
 *
 *  Created on: 11.10.2026
 *      Author: n3034770
 */

#include "pbma.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void SelectionSort(vector<int> &a) {
	for (size_t i = 0; i < a.size() - 1; i++) {
		size_t min = i;
		for (size_t j = i + 1; j < a.size(); j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(a, min, i);
		}
	}
}
void InsertionSort(vector<int> &a) {
	for (size_t i = 1; i < a.size(); i++) {
		size_t j = i;
		while ((j > 0) and (a[j - 1] > a[j])) {
			swap(a, j - 1, j);
			j -= 1;
		}
	}
}
inline void MyCopy(vector<int> &a, vector<int> &b, size_t from, size_t to) {
	for (size_t idx = from; idx < to; idx++) {
		a[idx] = b[idx];
	}
}
void Mergen(vector<int> &a, vector<int> &b, int start_links, int end_links,
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

void MergeSort(vector<int> &a, vector<int> &b, int links, int rechts) {
	if (links == rechts)
		return;
	size_t mitte = links + (rechts - links) / 2;
	MergeSort(a, b, links, mitte);
	MergeSort(a, b, mitte + 1, rechts);
	Mergen(a, b, links, mitte, mitte + 1, rechts);
}

void MergeSort(vector<int> &a) {
	int links = 0;
	int rechts = a.size() - 1;
	vector<int> b(a.size());
	MergeSort(a, b, links, rechts);
}

int main() {
	
	vector<int> vec = create_randints(10,0,100);
	int first_error;

	
	MergeSort(vec);
	for(size_t i = 0; i < vec.size(); i++)
	{
		cout << setw(2) << vec[i] ;
	}
	cout << endl;
	
	bool sorted = is_sorted(vec, first_error);
	bool check = check_sort(MergeSort, true);
	cout << sorted << endl;
	cout << check << endl;
	
	
	


	return 0;
}


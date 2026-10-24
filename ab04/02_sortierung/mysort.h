/*
 * mysort.h
 *
 *  Created on: 16.10.2026
 *      Author: n3034770
 */

#ifndef MYSORT_H_
#define MYSORT_H_

#include <vector>

void mysort(std::vector<int>& numbers);
void MergeSort(std::vector<int> &a);
void Mergen(std::vector<int> &a, std::vector<int> &b, int start_links, int end_links,
		int start_rechts, int end_rechts);
inline void MyCopy(std::vector<int> &a, std::vector<int> &b, size_t from, size_t to);



#endif /* MYSORT_H_ */

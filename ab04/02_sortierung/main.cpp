/*
 * sort.cpp
 *
 *  Created on: 16.10.2026
 *      Author: n3034770
 */

#include <iostream>
#include <vector>
#include "pbma.h"
#include "mysort.h"

using namespace std;





int main()
{

		int min = -6;
		int max = 6;
		int n = 30;
		int fe1, fe2;
		vector<int> a = create_randints(n,min,max);

		vector<int> b = create_randints(n,min,max);


		mysort(a);
		is_sorted(a, fe1);
		check_sort(mysort, true, true);

		MergeSort(b);
		is_sorted(b, fe2);
		check_sort(MergeSort, true, true);



	return 0;
}



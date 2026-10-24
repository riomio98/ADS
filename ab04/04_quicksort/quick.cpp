/*
 * quick.cpp
 *
 *  Created on: 24.10.2026
 *      Author: n3034770
 */


#include "pbma.h"
#include "quick.h"
#include <vector>

using namespace std;


void quicksort_rec(vector<int>& a, size_t li, size_t re)
{
	// 1. Abbruch: nur ein Element
	if(li == re)
	{
		return;
	}
	// 2. start/end merken, Pivot bestimmen
	size_t bgn = li;
	size_t end = re;
	int mi = li + (re-li)/2;
	int piv = a[mi];
	// 3. li von links, re von rechts gegen Pivot laufen lassen
	do {
		// 4. li/re auswerten: < tauschen, == Sonderfall, > fertig
		while(a[li] < piv){
			li++;
		}
		while(a[re] > piv){
			re--;
		}
		if(li < re){
			swap(a, li,re);
			li++;
			re--;
		}
		else if(li == re)
		{
			if(li == bgn)
			{
				li++;
			}
			else{
				re--;
			}
		}
		else {
		}
	}
	while(li <= re); // Fortsetzung der do while
	// 5. QuickSort auf beide Teilbereiche
	quicksort_rec(a, bgn, re); // linke begrenzung
	quicksort_rec(a, li, end); // rechte begrenzung
}

void quicksort(vector<int>& a)
{

    quicksort_rec(a, 0, a.size() - 1);
}



int main()
{

	vector<int> a = create_randints(10,0,100);

	quicksort(a);
	int err =0;
	check_sort(quicksort, true, true);
	bool check = is_sorted(a, err);
	if(check)
		cout << "True" << endl;
	else
		cout << "False" << endl;


	return 0;
}


/*
 * main.cpp
 *
 *  Created on: 17.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
using namespace std;

struct intvec {
    size_t cap;
    size_t size;
    int* arr;
};

void intvec_pushback(intvec* v, int ele)
{


	if(v->cap > v->size)
	{
		v->arr[v->size] = ele;
		v->size++;
	}
	else
	{
		size_t new_cap;

		if (v->cap == 0)
		    new_cap = 1;
		else
		    new_cap = v->cap * 2;

		int* neu = new int[new_cap];

		for(size_t i = 0; i < v->size; i++)
		{
			neu[i] = v->arr[i];
		}
		delete [] v->arr;

		v->arr = neu;
		v->cap = new_cap;
		v->arr[v->size] = ele;
		v->size++;

	}
}



int main()
{
	intvec* v = new intvec;
	v->size = 0;
	v->cap = 0;
	v->arr = new int[v->cap];

	intvec_pushback(v, 12);
	intvec_pushback(v, 1);
	intvec_pushback(v, 3);

	delete [] v->arr;
	delete v;

	return 0;
}




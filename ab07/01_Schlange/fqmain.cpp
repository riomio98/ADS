/*
 * main.cpp
 *
 *  Created on: 13.11.2026
 *      Author: n3034770
 */

//#include "pbma.h"
#include "flexqueue.h"
#include "flexqueue.h"
#include <iostream>
#include <cassert>

using namespace std;

int abzaehlreim(size_t n, int k)
{
	Queue q;
	init(q, n);

	for(size_t i = 0; i < n; i++)
	{
		enter(q, i);
	}


	while(n > 1)
	{
		for(int i = 0; i < k-1; i++)
		{
			int actual_kid = front(q);
			leave(q);
			enter(q, actual_kid);
		}
		leave(q);
		n--;
	}
	return front(q);
}

int main()
{

	size_t n = 10;
	int k = 2;

	cout << "gewinner: " <<  abzaehlreim(n,k) << endl;;

    return 0;
}

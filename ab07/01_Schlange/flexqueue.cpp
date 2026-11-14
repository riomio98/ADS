/*
 * flexqueue.cpp
 *
 *  Created on: 13.11.2026
 *      Author: n3034770
 */


//#include "pbma.h"
#include "flexqueue.h"
#include <stdexcept>

bool empty(Queue& q)
{
	return (q.head == q.tail);
}

bool full(Queue& q)
{
	return (q.tail+1) % (q.cap+1)  == q.head;
}

int front(Queue& q)
{
	if(empty(q))
	{
		throw std::runtime_error("front() : underflow");
	}
	return q.arr[q.head];
}

void init(Queue& q, size_t capacity)
{

		q.cap = capacity;
		q.arr = new int[q.cap+1];
		q.head = 0;
		q.tail = 0;
}

void clear(Queue& q)
{
	delete [] q.arr;
	q.arr = nullptr;
	q.head = 0;
	q.tail = 0;
	q.cap = 0;
}

void enter(Queue& q, int x)
{
	if(full(q))
	{
		Queue tmp;
		tmp.cap = q.cap*2;
		tmp.arr = new int[tmp.cap+1];
		for(size_t i = 0; i < q.cap; i++)
		{
		    size_t idx = (q.head + i) % (q.cap + 1);
		    tmp.arr[i] = q.arr[idx];
		}
		delete [] q.arr;
		q.arr = nullptr;
		tmp.head = 0;
		tmp.tail = q.cap;
		q = tmp;

		q.arr[q.tail] = x;
		q.tail = (q.tail + 1) % (q.cap + 1);
	}
	else
	{
		q.arr[q.tail] = x;
		q.tail = (q.tail + 1) % (q.cap + 1);
	}
}

void leave(Queue& q)
{
    if(empty(q))
    {
        throw std::runtime_error("leave(): underflow");
    }


    q.head = (q.head + 1) % (q.cap + 1);

    size_t count = (q.tail + (q.cap + 1) - q.head) % (q.cap + 1);

    if(q.cap > 1 && count * 4 < q.cap)
    {
        Queue tmp;

        tmp.cap = q.cap / 2;
        tmp.arr = new int[tmp.cap + 1];

        for(size_t i = 0; i < count; i++)
        {
        	size_t idx = (q.head + i) % (q.cap + 1);
            tmp.arr[i] = q.arr[idx];
        }

        tmp.head = 0;
        tmp.tail = count;

        delete[] q.arr;
        q = tmp;
    }
}

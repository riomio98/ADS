/*
 * flexqueue.h
 *
 *  Created on: 13.11.2026
 *      Author: n3034770
 */

#ifndef FLEXQUEUE_H_
#define FLEXQUEUE_H_

#include <cstddef>

struct Queue
{
	int* arr;
	size_t cap;
	size_t head;
	size_t tail;
};

void init(Queue& q, size_t cap = 1);
void clear(Queue& q);
bool full(Queue& q);
int front(Queue& q);
bool empty(Queue& q);
void enter(Queue& q, int x);
void leave(Queue& q);





#endif /* FLEXQUEUE_H_ */

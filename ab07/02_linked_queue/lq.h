/*
 * lq.h
 *
 *  Created on: 20.11.2026
 *      Author: n3034770
 */

#ifndef LQ_H_
#define LQ_H_

#include <cstddef>
#include <string>

struct node
{
	std::string val;;
	node* next;

};

struct linked_queue {
    node* head;
    node* tail;
};


void lqueue_enter(linked_queue* lq, std::string s);
std::string lqueue_leave(linked_queue* lq);
bool lqueue_is_empty(linked_queue* lq);
size_t lqueue_size(linked_queue* lq);
void lqueue_enter(linked_queue* lq, std::string s);
std::string lqueue_leave(linked_queue* lq);
bool lqueue_is_empty(linked_queue* lq);
size_t lqueue_size(linked_queue *lq);


#endif /* LQ_H_ */

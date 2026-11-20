/*
 * lq.cpp
 *
 *  Created on: 20.11.2026
 *      Author: n3034770
 *
 *
 *
 /
  *
  *
  */
#include "lq.h"
#include <cstddef>
#include <string>
#include <stdexcept>

void lqueue_enter(linked_queue* lq, std::string s) {


	if(lq->head == nullptr)
	{
		node* new_entry = new node;
		new_entry->val = s;
		new_entry->next = nullptr;
		lq->head = new_entry;
	}
	else{
		node* new_entry = new node;
		new_entry->val = s;
		new_entry->next = nullptr;
		lq->tail->next = new_entry;  // Alter letzter Knoten zeigt auf neuen
		lq->tail = new_entry;        // tail zeigt jetzt auf neuen Knoten
	}
}

std::string lqueue_leave(linked_queue *lq) {

	if(lq->head == nullptr)
	{
		throw std::runtime_error("leer");
	}
	else{

		node* i = lq->head;

		std::string value = i->val;  // Wert merken
		lq->head = i->next;
		delete i;

		if(lq->head == nullptr) // nach löschen keine elemente mehr ?
		{
			lq->tail = nullptr; // dann muss tail auch auf nullptr
		}

		return value;
	}




}

bool lqueue_is_empty(linked_queue *lq) {
	return (lq->head == nullptr);
}

size_t lqueue_size(linked_queue *lq) {
	node* i = lq->head;
	int cnt =0;
	while(i != nullptr)
	{
		i = i->next;
		cnt++;
	}
	return cnt;
}


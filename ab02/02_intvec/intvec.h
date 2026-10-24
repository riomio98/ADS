/*
 * intvec.h
 *
 *  Created on: 30.09.2026
 *      Author: n3034770
 */

#ifndef INTVEC_H_
#define INTVEC_H_

#ifndef INTVEC_H
#define INTVEC_H




struct intvec {
    size_t capacity; // anz allokierter ints
    size_t size; // anz verwendete ints
    int *arr;
};

void ivec_init(intvec* ivec, size_t cap);

void ivec_clear(intvec* ivec);

void ivec_pushback(intvec* ivec, int ele);

int& ivec_at(intvec* ivec, size_t idx);

int ivec_sum(intvec* ivec);

#endif



#endif /* INTVEC_H_ */

/*
 * intvec.cpp
 *
 *  Created on: 30.09.2026
 *      Author: n3034770
 */
#include <iostream>
#include "intvec.h"
#include <cstdlib>

using namespace std;

void ivec_init(intvec* ivec, size_t cap)
{
    ivec->arr = new int[cap];
    ivec->size = 0;
    ivec->capacity = cap;
}

void ivec_clear(intvec* ivec)
{
    ivec->size = 0;
    ivec->capacity = 0;

    delete[] ivec->arr;
    ivec->arr = nullptr;
}

void ivec_pushback(intvec* ivec, int ele)
{
    if(ivec->size < ivec->capacity)
    {
        ivec->arr[ivec->size] = ele;
        ivec->size++;

    }
    else
    {
       size_t new_cap = ivec->capacity * 2;
       int* new_arr = new int[new_cap];

       for(size_t i = 0; i < ivec->size; i++)
       {
            new_arr[i] = ivec->arr[i];
       }
        delete[] ivec->arr;
        ivec->arr = new_arr;
        ivec->capacity = new_cap;
        ivec->arr[ivec->size] = ele;
        ivec->size++;

    }
}

int& ivec_at(intvec* ivec, size_t idx)
{
    if(idx >= ivec->size)
    {
        cout << "ERROR: INDEX NOT IN RANGE" << endl;
        exit(1);
    }
    else
    {
        return ivec->arr[idx];
    }
}


int ivec_sum(intvec* ivec)
{
    int sum_size = 0;
    for(size_t i = 0; i < ivec->size; i++)
    {
        sum_size += ivec->arr[i];
    }
    return sum_size;
}




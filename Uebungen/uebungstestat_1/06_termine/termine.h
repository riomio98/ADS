/*
 * termine.h
 *
 *  Created on: 15.11.2026
 *      Author: n3034770
 */

#ifndef TERMINE_H_
#define TERMINE_H_

#include <vector>


struct Termin {
    int start;
    int ende;
};

int max_termine_iterativ(const std::vector<Termin>& termine);
int max_termine_rekursiv(const std::vector<Termin>& termine);
int helper(const std::vector<Termin>& termine,size_t i,int res, int letztes_ende);
#endif /* TERMINE_H_ */

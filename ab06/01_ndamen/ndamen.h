/*
 * ndamen.cpp
 *
 *  Created on: 07.11.2026
 *      Author: n3034770
 */

#ifndef NDAMEN_CPP_
#define NDAMEN_CPP_

#include <vector>
#include "pbmag.h"


extern Board* board;
extern bool display;

int solve_sum_damen(std::vector<int>& v, int row);
bool solve_ndamen(std::vector<int>& v, int row);
bool assign_ok(const std::vector<int>& v, int row, int col);


#endif /* NDAMEN_CPP_ */

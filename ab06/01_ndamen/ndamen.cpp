/*
 * ndamen.cpp
 *
 *  Created on: 07.11.2026
 *      Author: n3034770
 */

#include "ndamen.h"
#include "pbma.h"

Board* board;
bool display;

int solve_sum_damen(std::vector<int>& v, int row)
{
	int n = v.size();

	if(n == row)
	{
		return 1;
	}
	int sum = 0;
	for(int col = 0; col < n; ++col)
	{
		if(assign_ok(v,row,col))
		{
			v[row] = col;

			sum += solve_sum_damen(v, row+1);
			v[row] = -1;
		}
	}
	return sum;
}

bool solve_ndamen(std::vector<int>& v, int row)
{
	int n = v.size();

	if(n == row)
	{
		return true;
	}
	for(int col = 0; col < n; ++col)
	{
		if(assign_ok(v,row,col))
		{
			v[row] = col;
			if(display)
			{
				board->setSquare(row, col, Gruen);
				board->render();
				schlafe_ms(30);

			}

			if(solve_ndamen(v, row+1))
			{
				return true;
			}
			v[row] = -1;
			if(display)
			{
				board->resetSquare(row, col);
				board->render();
				schlafe_ms(30);
			}

		}
	}
	return false;
}


bool assign_ok(const std::vector<int>& v, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		if(v[i] == col)
		{
			return false;
		}
		if(v[i] == col -(row-i))
		{
			return false;
		}
		if(v[i] == col + (row -i))
		{
			return false;
		}
	}
	return true;
}

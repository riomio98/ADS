/*
 * main.cpp
 *
 *  Created on: 07.11.2026
 *      Author: n3034770
 */


#include "ndamen.h"
#include <vector>
#include "pbma.h"
#include <stdexcept>
#include "pbmag.h"
#include <iostream>

using namespace std;


int main(int argc, const char* argv[])
{
	args_t args(argc, argv);

	size_t N = args.int_option("n",16);
	bool solutions = args.flag("a");
	display = args.flag("p");

	if(display)
	{
		board = new Board(N);
	}

	if(N == 0)
	{
		throw runtime_error("Playground val must be greater than 0");
	}
	vector<int> v(N, -1);

	if(solutions)
	{
		Timer t1;
		cout << solve_sum_damen(v,0) <<endl;
		cout << t1.human_measure() << endl;
	}
	else{

		Timer t2;
		int cnt = solve_ndamen(v,0);
		cout << cnt << endl;
		cout << t2.human_measure() << endl;
	}




	delete board;
	return 0;
}

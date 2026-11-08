#include <vector>
#include <iostream>
#include <stdexcept>
#include "pbma.h"
#include <string>

using namespace std;

long checks = 0;
long trys = 0;

int assign_ok(const std::vector<int>& v, int idx, int zahl)
{

	checks++;
	int row = idx/9;
	int col = idx%9;

	for(int c = 0; c < 9; c++)
	{
		if(v[row * 9 + c] == zahl)
		{
			return false;
		}
	}
	for(int r = 0; r < 9; r++)
	{
		if(v[r * 9 + col] == zahl)
		{
			return false;
		}
	}

	int br = row/3*3;
	int bc = col/3*3;
	for(int r = br; r < br +3; r++)
	{
		for(int c = bc; c < bc+3; c++)
		{
			if(v[r*9+c] == zahl)
			{
				return false;
			}
		}
	}

	return true;
}


bool solve_sudoku(std::vector<int>& v, int idx)
{
	int n = v.size();
	if(n == idx)
	{
		return true;
	}
	if(v[idx] != 0)
	{
		return solve_sudoku(v, idx+1);
	}
	for(int zahl = 1; zahl < 10; zahl++)
	{
		if(assign_ok(v, idx, zahl))
		{
			v[idx] = zahl;
			trys++;
			if(solve_sudoku(v, idx+1))
			{
				return true;
			}
			v[idx] = 0;
		}
	}
	return false;
}

void print_sudoku(vector<int>& v)
{
	for(size_t i = 0; i < v.size(); i++)
	{
		int row = i/9;
		int col = i%9;
		if(v[i] == 0)
		{
			cout << " . ";
		}
		else
		{
			cout << " " << v[i] << " ";
		}
		if(col == 2|| col == 5)
		{
			cout << "|";
		}
		if(col==8)
		{
			cout << endl;
			if(row == 2 || row == 5)
			{
				cout << "-----------------------------" << endl;
			}
		}
	}

}

int main(int argc, const char* argv[])
{
	args_t args(argc, argv);

	string file = args.pos(0, "puzzle1.sudoku");
	vector<int> v = read_ints(file);
	cout << "Task:" << endl;
	print_sudoku(v);

	Timer t;
	solve_sudoku(v,0);
	string dauer = t.human_measure();

	cout << "Lösung: " << endl;
	print_sudoku(v);
	cout << "Versuche: " << trys << ", ";
	cout << "Checks: " << checks << ", ";
	cout << "Dauer: " << dauer << endl;;

	return 0;
}

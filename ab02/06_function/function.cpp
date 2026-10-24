/*
 * function.cpp
 *
 *  Created on: 03.10.2026
 *      Author: n3034770
 */


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int func(int x){

    if(x > 100)
    {
        return x - 10;
    }
    else
    {
        return func(func(x + 11));
        // BSP: x = 99 -> 99 > 100 -> false ->
        // innere funktion: (99 + 11) - 10 = 100 ->
        // 100 > 100 -> false ->
        // innere funktion: (100 + 11) - 10 = 101 ->
        // äußere funktion: 101 > 100 -> true -> 101 - 10 = 91
    }

}


int func_optim(int x){

    if(x <= 100)
    {
        return 91;
    }
    else
    {
        return x - 10;
    }
}


int main()
{
    vector<int> rand_numbers;
    cout << left << setw(2) << "x:" << right;
    for(int i = 0; i < 41; i++)
    {
        rand_numbers.push_back(i+80);
        cout << setw(4) << rand_numbers[i];

    }
    cout << endl;


    cout << left << setw(2) << "y:" << right;
    for(size_t i = 0; i < rand_numbers.size(); i++)
    {
        int y = func(rand_numbers[i]);
        cout << setw(4) << y;

    }
    cout << endl;
    cout << left << setw(2) << "y2:" << right;
    for(size_t i = 0; i < rand_numbers.size(); i++)
    {
        int y_optim = func_optim(rand_numbers[i]);
        cout << setw(4) << y_optim;

    }




    return 0;
}


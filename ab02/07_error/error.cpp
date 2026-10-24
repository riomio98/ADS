/*
 * error.cpp
 *
 *  Created on: 04.10.2026
 *      Author: n3034770
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double little_gauss( vector<double>& vec)
{

    double error = 0.0;
    while(error < 1.0)
    {
        double sum_f = 0.0;
        double sum_r = 0.0;
        for(size_t i = 0; i < vec.size(); i++)
        {
            sum_f += vec[i];
            sum_r += vec[vec.size()-1-i];
        }

        error = fabs(sum_f - sum_r);
        if(error < 1.0)
        {
        	vec.back() *= 10;
        }
    }

    return error;
}


int main()
{

    vector<double> vec = {1.0, 1.0, 1.0, 1e+3};

    cout << fixed << "Error: " << setprecision(2) << little_gauss(vec) << endl;
    cout << fixed << "double number where error > 1.00: " << scientific << vec.back() << endl;


    return 0;
}



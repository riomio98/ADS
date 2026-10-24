/*
 * logtable.cpp
 *
 *  Created on: 02.10.2026
 *      Author: n3034770
 */




#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "pbma.h"
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{

    args_t args(argc, argv);
    double start = args.double_option("start", 1.0);
    double step = args.double_option("step", 1.0);
    double base = args.double_option("base", 2.0);
    int perline = args.int_option("perline",5);
    int anzahl = args.int_pos(0, 0);

    if(anzahl == 0){
        cin >> start;
        cin >> step;
        cin >> base;
        cin >> perline;
        cin >> anzahl;

    }

    cout << "log table: " << "base=" << base << ", " << "start=" << start << ", "  << "step=" << step << ": " << anzahl << " elements" << endl;

    double x = start;
    for(int i = 0; i < anzahl; i++)
    {
        cout << fixed
            << setprecision(1) << setw(5) << x << ": "
            << setprecision(4) << setw(6) << log(x) / log(base);
        x += step;
        if((i+1) % perline == 0)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    return 0;
}

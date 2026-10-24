/*
 * main.cpp
 *
 *  Created on: 26.09.2026
 *      Author: n3034770
 */
/*
 * heron.cpp
 *
 *  Created on: 25.09.2026
 *      Author: n3034770
 */

#include <iostream>
#include <cmath>
#include "pbma.h"

using namespace std;

// Naehert sqrt(x) mit dem Heron-Verfahren an, bis sich a_i und a_i+1
// um weniger als eps unterscheiden.
double heron(double x, double eps)
{
  double a = (1 + x) / 2;   // a0
  double a_neu;
  double diff;
  do
  {
    a_neu = (a + x / a) / 2;   // a_i+1
    diff = fabs(a_neu - a);
    a = a_neu;
  } while (diff >= eps);

  return a;
}

int main(int argc, const char* argv[])
{
  args_t args(argc, argv);
  double x   = args.double_pos(0, 10.0);   // Vorgabe x = 10.0
  double eps = args.double_pos(1, 1e-6);   // Vorgabe eps = 1e-6

  cout << "heron(" << x << ", " << eps << ") = " << heron(x, eps) << endl;

  return 0;
}





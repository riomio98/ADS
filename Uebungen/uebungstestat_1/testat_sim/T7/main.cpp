/*
 * main.cpp
 *
 *  Created on: 14.11.2026
 *      Author: n3034770
 */

#include <vector>
#include <cstddef>
#include "testat7.h"
#include <iostream>
#include "pbma.h"

using namespace std;

int main()
{

	text_t text = {"Hallo", "du", "Welt", "spalte"};
	zeilen_t res;
	umbruch_endrek(text, 0,8 ,res);

	return 0;
}

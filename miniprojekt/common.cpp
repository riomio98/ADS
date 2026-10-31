/*
 * common.cpp
 *
 *  Created on: 30.10.2026
 *      Author: n3034770
 */
#include "pbma.h"
#include "common.h"
#include <vector>
#include <cmath>



//kosten pro zeile
long zeilenkosten(int zb, int b) // pow((zeilenbreite - b),2)
{
	return (b - zb) * (b - zb);
	//kosten für einzelne Zeile!
}
//Umbruch des textes
std::vector<int> umbruch(std::vector<std::string> text, int b)
{
	std::vector<int> zeilen;

    if(text.empty())
    {
        return zeilen;
    }

	zeilen.push_back(0);

	int actual = 0;

	for(size_t i = 0; i < text.size(); i++)
	{

		int word_len = text[i].size();

		if(actual == 0)
		{
			actual = word_len;
		}
		else if((word_len + 1) + actual  <= b)
		{
			actual += word_len + 1;
		}
		else
		{
			zeilen.push_back(i);
			actual = word_len;
		}
	}
	return zeilen;
}
//gesamtkosten



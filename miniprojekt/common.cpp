/*
 * common.cpp
 *
 *  Created on: 30.10.2026
 *      Author: n3034770
 */
#include "pbma.h"
#include "common.h"
#include <vector>
#include <stdexcept>
#include <format>



//kosten pro zeile
long zeilenkosten(int zb, int b) // pow((zeilenbreite - b),2)
{
	long diff = (b - zb);

	return diff * diff;
	//kosten für einzelne Zeile in long!
}
// zeilenbreite zb
int zeilenbreite(const std::vector<std::string>& text, int start, int ende)
{
	int zb = 0;
	for(int i = start; i < ende; i++)
	{
		if(i == start)
		{
			zb += text[i].size(); // erstes Wort kein leerzeichen
		}
		else{
			zb += text[i].size() + 1; // + leerzeichen
		}
	}
	return zb;
}
//Umbruch des textes
std::vector<int> umbruch(std::vector<std::string>& text, int b)
{
	std::vector<int> zeilen;

    if(text.empty())
    {
        return zeilen;
    }

	zeilen.push_back(0);

	int actual_len = 0;

	for(size_t i = 0; i < text.size(); i++)
	{

		int word_len = text[i].size();
		if(word_len > b)
		{
			throw std::runtime_error("Wort: "
					+ text[i] + "ist zu Gross");
		}

		if(actual_len == 0)
		{
			actual_len = word_len;
		}
		else if((word_len + 1) + actual_len  <= b)
		{
			actual_len += word_len + 1;
		}
		else
		{
			zeilen.push_back(i);
			actual_len = word_len;
		}
	}
	return zeilen;
}
//gesamtkosten
long gesamtkosten(const std::vector<std::string>& text,
		const std::vector<int>& zeilen, int b)
{
	long sum_cost = 0;
	for(size_t i = 1; i < zeilen.size();i++)
	{
		// bis vorletzte Zeile
		int zb = zeilenbreite(text,zeilen[i-1], zeilen[i]);
		sum_cost += zeilenkosten(zb, b);
	}
	return sum_cost;
}

//Ausgabe
void print_umbruch(const std::vector<std::string>& text,
		const std::vector<int>& zeilen, long& cost, bool format_cost, int b)
{
	for(size_t i = 0; i < zeilen.size(); i++)
	{
		size_t start = zeilen[i];
		size_t ende;
		if(i == zeilen.size()-1)
		{
			ende = text.size();
		}
		else
		{
			ende = zeilen[i+1];
		}
		if(format_cost) // flag -z
		{
			if(i == zeilen.size()-1) // letzte zeile
			{
				std::cout << format(0,5) << " ";
			}
			else //sonstige zeilen
			{
				int zb = zeilenbreite(text,start, ende);
				std::cout << format(zeilenkosten(zb,b),5) << " ";
			}
		}
		for(size_t j = start; j < ende; j++)
		{

			if(j < ende-1)
			{
				std::cout << text[j] << " ";
			}

			else
			{
				std::cout << text[j];
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Zeilen: " << zeilen.size() << ", Kosten: " << cost << std::endl;
}



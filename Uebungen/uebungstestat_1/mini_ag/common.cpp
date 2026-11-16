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

void umbruch_rek(std::vector<std::string>& text,
		size_t idx, int cap, int b, std::vector<int>& zeilen)
{
	if(idx == text.size())
	{
		return;
	}
	int word_len = text[idx].size();
	if(word_len > b)
	{
		throw std::runtime_error("Wort: "
				+ text[idx] + "ist zu Gross");
	}
	if(cap == b)
	{
		if(word_len <= cap)
		{
			cap-= word_len;
			umbruch_rek(text, idx+1, cap, b, zeilen);
		}
	}
	else if(cap < b)
	{
		if(word_len + 1 <= cap)
		{
			cap-= word_len + 1;
			umbruch_rek(text, idx+1, cap, b, zeilen);
		}
		else
		{
			zeilen.push_back(idx);
			cap = b;
			umbruch_rek(text, idx, cap, b, zeilen);
		}
	}
}

std::vector<int> umbruch_rek(std::vector<std::string>& text, int b)
{
	std::vector<int> zeilen;

    if(text.empty())
    {
        return zeilen;
    }
    zeilen.push_back(0);
    size_t idx = 0;
    int cap = b;
	umbruch_rek(text, idx, cap, b, zeilen);

    return zeilen;
}

//Umbruch des textes
std::vector<int> umbruch(std::vector<std::string>& text, int b)
{
	std::vector<int> v;
	if(text.empty())
	{
		return v;
	}
	v.push_back(0);
	int actual_len = text[0].size();
	for(size_t idx = 1; idx < text.size(); idx++)
	{
		if(text[idx].size() > b)
		{
			throw std::runtime_error("Wort zu lang");
		}
		if(actual_len + 1 + text[idx].size() <= b)
		{
			actual_len += 1 + text[idx].size();
		}
		else if(actual_len + 1 + text[idx].size() > b)
		{
			v.push_back(idx);
			actual_len = text[idx].size();
		}
	}
	return v;

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


long gesamtkosten_rek(
	const std::vector<std::string>& text,
    const std::vector<int>& zeilen,
    int b, size_t i, long cost
)
{
	if(i >= zeilen.size()-1)
	{
		return 0;
	}
	if(i < zeilen.size())
	{
		int zb = zeilenbreite(text,zeilen[i], zeilen[i+1]);
		cost += zeilenkosten(zb, b);
	}
	return gesamtkosten_rek(text, zeilen, b, i+1, cost);

}

long gesamtkosten_rek(
    const std::vector<std::string>& text,
    const std::vector<int>& zeilen,
    int b
)
{
	if(text.empty())
	{
		return 0;
	}
	return gesamtkosten_rek(text, zeilen, b, 0, 0);
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



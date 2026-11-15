// testat1.cpp - Probetestat 1: Rekursion ohne Schleifen
// Hier implementierst du. Alle Funktionen werfen zunaechst "noch nicht implementiert".
#include "testat1.h"
#include "common.h"   // deine Miniprojekt-Funktionen: zeilenbreite, zeilenkosten, umbruch, gesamtkosten
#include <stdexcept>
#include <cctype>

int anzahl_lang(const text_t& text, int idx, int min_len) {
    if(size_t(idx) >= text.size())
    {
    	return 0;
    }
    if(text[idx].size() >= size_t(min_len))
    {

    	return 1 +  anzahl_lang(text, idx+1, min_len);
    }
    else
    {
    	return 0+ anzahl_lang(text, idx+1, min_len);
    }

}

std::string umdrehen(const std::string& w) { // Spalte
	if(w.size() == 0)
	{
		return "";
	}
	return  umdrehen(w.substr(1)) + w[0];

}

bool ist_palindrom(const std::string& w, int lo, int hi) {
	if (lo >= hi)
	{
	    return true;
	}
    if(std::tolower(w[lo]) == std::tolower(w[hi]))
    {
    	lo++;
    	hi--;
    	return ist_palindrom(w,lo,hi);
    }


    return false;


}

int zaehle_zeichen(const std::string& w, char c, int i)
{
	if(i >= w.size())
	{
		return 0;
	}
	if(w[i] == c)
	{
		return 1 + zaehle_zeichen(w,c,i+1);
	}
	else
	{
		return 0 + zaehle_zeichen(w,c,i+1);
	}
}

std::string verbinde(const text_t& text,
		int von, int bis, const std::string& sep)
{
	if(von >= bis)
    {
    	return "";
    }
    if(von == bis-1)
	{
		return text[von];
	}
    else
    {
    	return text[von] + sep + verbinde(text, von +1, bis, sep);
    }

}

int index_von(const text_t& text, const std::string& wort, int idx)
{
	if(idx >= text.size())
	{
		return -1;
	}
	if(text[idx] == wort)
	{
		return idx;
	}
	else
	{
		return index_von(text, wort, idx+1);
	}
}

int anzahl_palindrome(const text_t& text, int idx)
{
	if(idx >= text.size())
	{
		return 0;
	}
	if(ist_palindrom(text[idx], 0, text[idx].size()-1))
	{

		return 1 + anzahl_palindrome(text, idx+1);
	}
	else
	{
		return 0 + anzahl_palindrome(text, idx+1);
	}

}

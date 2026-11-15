// testat7.cpp - Probetestat 7: Umbruch auf fuenf Arten
// Hier implementierst du. Alle Funktionen werfen zunaechst "noch nicht implementiert".
#include "testat7.h"
#include "common.h"   // deine Miniprojekt-Funktionen: zeilenbreite, zeilenkosten, umbruch, gesamtkosten
#include <stdexcept>

zeilen_t umbruch_zeilenweise(const text_t& text, int b) {
	zeilen_t v;

    for(size_t i = 0; i < text.size(); i++)
    {
    	v.push_back(i);
    	int actual_len = text[i].size();
    	if (actual_len > b)
    	{
    	    throw std::runtime_error("Wort zu lang");
    	}
    	size_t idx = i+1;
    	while(idx < text.size() && actual_len + 1 + text[idx].size() <= b)
    	{
    			actual_len += text[idx].size() +1;
    			idx++;
    	}
    	i = idx-1;
    }
    return v;
}

zeilen_t umbruch_zeilen_rek(const text_t& text, int start, int b)
{
    if (start >= static_cast<int>(text.size()))
    {
        return {};
    }

    int actual_len = text[start].size();

    if (actual_len > b)
    {
        throw std::runtime_error("Wort zu lang");
    }

    size_t idx = start + 1;

    while (idx < text.size() &&
           actual_len + 1 + text[idx].size() <= b)
    {
        actual_len += text[idx].size() + 1;
        idx++;
    }

    zeilen_t rest = umbruch_zeilen_rek(text, idx, b);
    rest.insert(rest.begin(), start);

    return rest;
}

void umbruch_endrek(const text_t& text, int start, int b, zeilen_t& zeilen) {
    if(start >= text.size())
    {
    	return;
    }
    int actual_len = text[start].size();
    zeilen.push_back(start);
    if (actual_len > b)
    {
        throw std::runtime_error("Wort zu lang");
    }
    size_t idx = start + 1;

    while (idx < text.size() &&
           actual_len + 1 + text[idx].size() <= b)
    {
        actual_len += text[idx].size() + 1;
        idx++;
    }
    umbruch_endrek(text, idx, b, zeilen);
}

std::vector<long> praefix(const text_t& text) {
	std::vector<long> p;

	p.push_back(0);
	int sum = 0;
	for (std::size_t i = 0; i < text.size(); ++i)
	{
		sum += text[i].size();
		p.push_back(sum);
	}
	return p;
}

long breite_p(const std::vector<long>& P, int von, int bis) {
	if(von >= bis)
	{
		return 0;
	}
	return (P[bis] - P[von]) + (bis -von) - 1;

}

int zeilenende(const std::vector<long>& P, int start, int b, int lo, int hi)
{
	int mi = lo + (hi-lo+1)/2;
	if(lo == hi)
	{
		return lo;
	}
	if(breite_p(P,start,mi) <= b)
	{
		return zeilenende(P,start,b,mi,hi);
	}
	else{
		return zeilenende(P,start,b,lo,mi-1);
	}
}

zeilen_t umbruch_binaer(const text_t& text, int b) {

    std::vector<long> pfix = praefix(text);
    zeilen_t res;
    int start = 0;
    int hi = text.size();
    for(const std::string& word : text)
    {
    	if(word.size() > b)
    	{
    		throw std::runtime_error("Wort zu gross");
    	}
    }
    while(start < text.size())
    {
    	int lo = start + 1;
    	res.push_back(start);
    	start = zeilenende(pfix, start,b,lo,hi);
    }

    return res;

}

long gesamtkosten_rek(const std::vector<long>& P, const zeilen_t& zeilen, int b, int k)
{
	if(k >= zeilen.size()-1)
	{
		return 0;
	}
	int zb = breite_p(P,zeilen[k], zeilen[k+1]);

	return zeilenkosten(zb, b) + gesamtkosten_rek(P, zeilen, b, k+1);

}




zeilen_t umbruch_von_hinten(const text_t& text, int b) {
    throw std::logic_error("umbruch_von_hinten: noch nicht implementiert");
}

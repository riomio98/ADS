// testat2.cpp - Probetestat 2: Zeilen setzen
// Hier implementierst du. Alle Funktionen werfen zunaechst "noch nicht implementiert".
#include "testat2.h"
#include "common.h"   // deine Miniprojekt-Funktionen: zeilenbreite, zeilenkosten, umbruch, gesamtkosten
#include <stdexcept>

std::string zeile(const text_t& text, int von, int bis) {
	if(von >= bis)
	{
		return "";
	}
	if(von == bis - 1)
	{
		return text[von];
	}
	else
	{
		return text[von] + " " +  zeile(text, von + 1, bis);
	}

}

std::string rechtsbuendig(const text_t& text, int von, int bis, int b) {

	std:: string s = zeile(text,von,bis);
	int size = s.size();
	if(size <= b)
	{
		std::string leer = std::string(b-size, ' ');
		s = leer + s;
		return s;
	}
	else
	{
		throw std::invalid_argument("invalid arg");
	}
}

std::string blocksatz(const text_t& text, int von, int bis, int b)
{
	std:: string s = zeile(text,von,bis);
	int size = s.size();
	if(size <= b)
	{
		int extra = b - size;
		std::string res = text[von];
		for(size_t i = von; i < bis; i++ )
		{
			if(i == 0)
			{
				res += std::string(extra%(bis-1), ' ');
				res += text[i];
			}
			res += std::string(extra/(bis-1), ' ');
			res += text[i];
		}
	}
}

std::vector<std::string> setze(const text_t& text, const zeilen_t& zeilen, int b, char modus) {
    throw std::logic_error("setze: noch nicht implementiert");
}

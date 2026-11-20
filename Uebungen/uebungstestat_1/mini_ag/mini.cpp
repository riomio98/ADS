/*
 * mini.cpp
 *
 *  Created on: 19.11.2026
 *      Author: n3034770
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

std::vector<int> umbruch_rek(
    const std::vector<std::string>& text,
    int start,
    int b,
	std::vector<int>& res
)
{

	if(start == static_cast<int>(text.size()))
	{
		return res;
	}
	int actual_len = text[start].size();
	if(actual_len > b)
	{
		throw std::runtime_error("wort ist zu gross");
	}
    // Ende der aktuellen Zeile bestimmen
    int ende = start + 1;

    while (ende < static_cast<int>(text.size()) &&
           actual_len + 1 + text[ende].size() <= b)
    {
        actual_len += 1 + text[ende].size();
        ende++;
    }
    res.push_back(start);

	// Restlichen Text rekursiv bearbeiten
	umbruch_rek(text, ende, b, res);

	return res;
}

std::vector<int> umbruch_rek(
		const std::vector<std::string>& text,
	    int start,
	    int b)
{
	std::vector<int> res;
    umbruch_rek(text, 0, b, res);

    return res;



}


int main()
{
    vector<string> text = {
        "aaa", "bb", "cc", "ddddd"
    };

    int b = 6;

    vector<int> res = umbruch_rek(text, 0,b);

    for (int i = 0; i < static_cast<int>(res.size()); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}

/*
 * main.cpp
 *
 *  Created on: 26.09.2026
 *      Author: n3034770
 */
#include<iostream>
#include<vector>
#include "pbma.h"
//#include <limits>
#include <climits>


using namespace std;

int cntWords(vector<string>& v_text)
{
	int words_cnt = 0;

	for (size_t i = 0; i < v_text.size(); i++)
	{
		words_cnt++;
	}

	return words_cnt;

}

int cntLetter(vector<string>& v_text)
{
	int letter_cnt = 0;

	for(size_t i = 0; i < v_text.size(); i++)
	{
		string words = v_text[i];
		letter_cnt += words.size();
	}


	return letter_cnt;
}

unsigned int shortest(vector<string>& v_text)
{
	unsigned int shortest = UINT_MAX;//numeric_limits<int>::max();

	for (size_t i = 0; i < v_text.size(); i++)
	{
		if(v_text[i].size() < shortest )
		{
			shortest = v_text[i].size();
		}
	}

	return shortest;
}

unsigned int longest(vector<string>& v_text)
{

	unsigned int longest = 0;//numeric_limits<int>::max();

	for (size_t i = 0; i < v_text.size(); i++)
	{
		if(v_text[i].size() > longest)
		{
			longest = v_text[i].size();
		}
	}
	return longest;
}


vector<int> firstLetters(vector<string>& v_text)
{
	vector<int> cnt_fl(26);
	char fl;
	for (size_t i = 0; i < v_text.size(); i++)
	{
		string letters = v_text[i];
		fl = letters[0];
		// fl = tolower(fl);
		if(fl >= 'A' and fl <= 'Z')
		{
			fl += ('a' - 'A');
		}
		int idx = fl - 'a';

		cnt_fl[idx]++;

	}

	return cnt_fl;
}

int main(int argc,const char* argv[])
{
	args_t args(argc, argv);

	string filename = args.pos(0, "atwi80d.txt");

	vector<string> v_text = read_words(filename);

	Timer timer0;
	int wc = cntWords(v_text);
	cout <<"Berechnungsdauer: " << timer0.human_measure() << endl;
	cout << "Words count: " << wc << endl;

	Timer timer1;
	int lc = cntLetter(v_text);
	cout <<"Berechnungsdauer: " << timer1.human_measure() << endl;
	cout << "Letter count: " << lc << endl;

	Timer timer2;
	unsigned int lw = longest(v_text);
	cout <<"Berechnungsdauer: " << timer2.human_measure() << endl;
	cout << "longest Word: " << lw << endl;

	Timer timer3;
	unsigned int  sw = shortest(v_text);
	cout <<"Berechnungsdauer: " << timer3.human_measure() << endl;
	cout << "shortest Word: " << sw << endl;

	Timer timer4;
	vector<int> cnt_fl = firstLetters(v_text);
	cout <<"Berechnungsdauer: " << timer4.human_measure() << endl;

	for(char i = 0; i < 26; i++)
	{
		char letter = 'a' + i;
		cout << letter << ": " << cnt_fl[i] << " ";
		if((i + 1) % 5 == 0)
			cout << endl;

	}
	cout << endl;

	return 0;
	}



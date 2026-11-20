/*
 * main.cpp
 *
 *  Created on: 20.11.2026
 *      Author: n3034770
 */

#include "lq.h"
#include <iostream>
#include <string>
#include "pbma.h"
#include <vector>

using namespace std;

int main(int argc, const char* argv[])
{
//	args_t args(argc, argv);
//	string fname = "text3.txt";
//	vector<string> v = read_words(fname);
//
//
//	linked_queue list;
//	list.head = nullptr;
//	for(size_t i = 0; i < v.size(); i++)
//	{
//		string word = v[i];
//		lqueue_enter(&list, word);
//	}
//	cout << lqueue_size(&list) << endl;

	linked_queue list;
	list.head = nullptr;
	list.tail = nullptr;
	cout << lqueue_is_empty(&list) << endl;;
	lqueue_enter(&list, "Hallo");
	lqueue_enter(&list, "du");
	lqueue_enter(&list, "Habbak");
	cout << lqueue_leave(&list) << endl;
	cout << lqueue_size(&list) << endl;
	cout << lqueue_is_empty(&list) << endl;;




	return 0;
}

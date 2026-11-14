/*
 * main.cpp
 *
 *  Created on: 13.11.2026
 *      Author: n3034770
 */

//#include "pbma.h"
#include "flexqueue.h"
#include "flexqueue.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    Queue q;
    init(q, 4);


    cout << "Test 1: Einfuegen" << endl;

    assert(empty(q));

    enter(q, 10);
    enter(q, 20);
    enter(q, 30);
    enter(q, 40);

    assert(full(q));
    assert(front(q) == 10);

    cout << "OK" << endl;



    cout << "Test 2: Vergroessern" << endl;

    enter(q, 50);

    assert(q.cap == 8);
    assert(front(q) == 10);

    cout << "OK" << endl;



    cout << "Test 3: FIFO" << endl;

    for(int x : {10, 20, 30, 40, 50})
    {
        assert(front(q) == x);
        leave(q);
    }

    assert(empty(q));

    cout << "OK" << endl;

    clear(q);



    cout << "Test 4: Umlauf" << endl;

    init(q, 4);

    enter(q, 10);
    enter(q, 20);
    enter(q, 30);
    enter(q, 40);

    leave(q);
    leave(q);

    enter(q, 50);
    enter(q, 60);

    assert(full(q));
    assert(front(q) == 30);

    cout << "OK" << endl;



    cout << "Test 5: Vergroessern nach Umlauf" << endl;

    enter(q, 70);

    for(int x : {30, 40, 50, 60, 70})
    {
        assert(front(q) == x);
        leave(q);
    }

    assert(empty(q));

    cout << "OK" << endl;



    cout << "Test 6: Wiederverwenden" << endl;

    enter(q, 99);

    assert(front(q) == 99);

    leave(q);

    assert(empty(q));

    cout << "OK" << endl;

    clear(q);

    cout << "\nALLE TESTS BESTANDEN!" << endl;

    return 0;
}

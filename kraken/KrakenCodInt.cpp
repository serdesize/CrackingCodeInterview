// KrakenCodInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

#include "linkedlist.h"
#include "arrays_strings.h"

int main()
{
	int numbers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ds::linkedlist<int> list;
	for (auto n : numbers)
		list.add(n);

	list.add(25, ds::linkedlist<int>::PositionInsert::Beginning);
	list.add(10, 5);
	list.remove(1);
	list.remove(0);


	Chap1 chap1;
	chap1.Run();


	std::cout << "Press any key to continue ... " << std::endl;
	std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

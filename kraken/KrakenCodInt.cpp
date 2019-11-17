// KrakenCodInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "linkedlist.h"
#include "hashtable.h"
#include "arrays_strings.h"

void test_linkedlist() 
{
	int numbers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ds::linkedlist<int> list;
	for (auto n : numbers)
		list.add(n);

	list.add(25, ds::linkedlist<int>::PositionInsert::Beginning);
	list.add(10, 5);
	list.remove(1);
	list.remove(0);
}

class AClass
{
public:
	int myInt = -1;
	std::string myString = "";
};

void test_hashtable() 
{
	ds::hash_table<std::string, AClass> table;
	AClass a;
	a.myInt = 1;
	a.myString = "simon";

	AClass b;
	b.myInt = 2;
	b.myString = "aylin";

	table.add("simon", &a);
	table.add("aylin", &b);

	b.myString = "aylin+simon";

	auto aylin = table.get("aylin");
	assert(aylin->myInt == 2);
	assert(aylin->myString == "aylin+simon");
	 
	table.remove("aylin");

	auto aylin2 = table.get("aylin");
	assert(aylin2 == nullptr);
}

int main()
{
	test_linkedlist();
	test_hashtable();


	Chap1 chap1;
	chap1.Run();


	std::cout << "Press any key to continue ... " << std::endl;
	std::cin.get();
}
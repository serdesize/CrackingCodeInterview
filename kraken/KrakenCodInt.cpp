// KrakenCodInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "arrays_strings.h"
#include "linkedlist.h"
#include "hashtable.h"
#include "bst.h"

#include "Algo_ThreeSum.h"
#include "LargestRectangleHistogram.h"
#include "RegularExpressisonMatchMaking.h"
#include "MostPeopleAlive.h"

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

void test_binarysearchtree() 
{
	ds::bstree<int> bst;
	bst.add(1);
	bst.add(9);
	bst.add(6);
	bst.add(4);
	bst.add(5);
	bst.add(8);
	bst.add(2);
	bst.add(3);
	bst.add(7);

	auto node = bst.find(2);
	assert(node->get_Data() == 2);
}

int main()
{
	//vector<int> vec = { 1, 1, -2 };
	//ThreeSum testThreeSum;
	//testThreeSum.threeSum(vec);

	//vector<int> vecTest1 = { 2, 1, 2 };
	//LargestRectangleHistogram testLargestRectangleHistogram;
	//testLargestRectangleHistogram.largestRectangleArea(vecTest1);

	//RegularExpressionMatchMaking exp;
	//auto match = exp.isMatch("aaaaaaaaaaaaaaaaaaaab", "a.*b");

	People p1(1900, 2000);
	People p2(1950, 2050);
	People p3(1938, 1985);
	People p4(1910, 1965);
	People p5(1936, 2019);
	People p6(1960, 2007);
	People p7(1956, 2015);
	People p8(1922, 1999);
	People p9(1901, 2001);
	People p10(1950, 1975);

	vector<People> peeps = { p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 };

	MostPeopleAlive mostPeopleAlive;
	auto daYear = mostPeopleAlive.YearWithMostPeople(peeps);

	test_linkedlist();
	test_hashtable();
	test_binarysearchtree();


	Chap1 chap1;
	chap1.Run();


	std::cout << "Press any key to continue ... " << std::endl;
	std::cin.get();
}
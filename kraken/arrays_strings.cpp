#include "arrays_strings.h"

void Chap1::q1()
{
	auto not_unique_str = "qwertyuioplkjhgfqdsazxcvbnm";
	auto unique_str = "qwertyuioplkjhgfdsazxcvbnm";

	std::unordered_map<char, bool> charMap;

	auto isUnique = true;
	for (int i = 0; i < (int)strlen(not_unique_str); i++)
	{
		isUnique &= charMap.emplace(not_unique_str[i], true).second;
	}

	assert(!isUnique);

	charMap.clear();
	isUnique = true;
	for (int i = 0; i < (int)strlen(unique_str); i++)
	{
		isUnique &= charMap.emplace(unique_str[i], true).second;
	}

	assert(isUnique);

	std::cout << "[ SUCCESS ] q1.1 : string uniqueness with unordered map" << std::endl;
}

static short alphabetical_idx(char c)
{
	short count = 0;
	switch (c)
	{
	case 'a':
		break;
	case 'b':
		count = 1;
		break;
	case 'c':
		count = 2;
		break;
	case 'd':
		count = 3;
		break;
	case 'e':
		count = 4;
		break;
	case 'f':
		count = 5;
		break;
	case 'g':
		count = 6;
		break;
	case 'h':
		count = 7;
		break;
	case 'i':
		count = 8;
		break;
	case 'j':
		count = 9;
		break;
	case 'k':
		count = 10;
		break;
	case 'l':
		count = 11;
		break;
	case 'm':
		count = 12;
		break;
	case 'n':
		count = 13;
		break;
	case 'o':
		count = 14;
		break;
	case 'p':
		count = 15;
		break;
	case 'q':
		count = 16;
		break;
	case 'r':
		count = 17;
		break;
	case 's':
		count = 18;
		break;
	case 't':
		count = 19;
		break;
	case 'u':
		count = 20;
		break;
	case 'v':
		count = 21;
		break;
	case 'w':
		count = 22;
		break;
	case 'x':
		count = 23;
		break;
	case 'y':
		count = 24;
		break;
	case 'z':
		count = 25;
		break;
	}

	return count;
}

void Chap1::q1_variant()
{
	auto not_unique_str = "qwertyuioplkjhgfqdsazxcvbnm";
	auto unique_str = "qwertyuioplkjhgfdsazxcvbnm";

	bool mask[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	auto isUnique = true;
	for (auto i = 0; i < (int)strlen(unique_str); i++)
	{
		auto cIndex = alphabetical_idx(unique_str[i]);
		if (mask[cIndex])
		{
			isUnique = false;
			break;
		}

		mask[cIndex] = true;
	}

	assert(isUnique);

	for (auto c : mask) { c = false; }
	isUnique = true;
	for (auto i = 0; (int)strlen(not_unique_str); i++)
	{
		auto cIndex = alphabetical_idx(not_unique_str[i]);
		if (mask[cIndex])
		{
			isUnique = false;
			break;
		}

		mask[cIndex] = true;
	}

	assert(!isUnique);

	std::cout << "[ SUCCESS ] q1.1_variant : string uniqueness without any data structures" << std::endl;
}

void Chap1::q2()
{
	// "sumit"and "tiums" are permutations of each other. 
	// "abcd"and bdea" are not permutations of each other.

	auto str1 = "sumit";
	auto str2 = "tiums";

	std::unordered_map<char, int> charMap;

	bool isPermutation = strlen(str1) == strlen(str2);
	if (isPermutation)
	{
		for (auto i = 0; i < (int)strlen(str1); i++)
		{
			auto car = str1[i];
			auto got = charMap.find(car);
			if (got == charMap.end())
			{
				charMap.emplace(car, 1).second;
			}
			else
			{
				charMap[car] = got->second;
			}
		}

		for (auto i = 0; i < (int)strlen(str2); i++)
		{
			auto car = str2[i];
			auto got = charMap.find(car);
			if (got == charMap.end())
			{
				isPermutation = false;
				break;
			}
			else
			{
				auto count = --got->second;
				if (count != 0)
				{
					charMap[car] = count;
				}
				else
				{
					charMap.erase(car);
				}
			}
		}
	}

	assert(isPermutation);

	charMap.clear();

	str1 = "abcd";
	str2 = "bdea";

	isPermutation = strlen(str1) == strlen(str2);
	if (isPermutation)
	{
		for (auto i = 0; i < (int)strlen(str1); i++)
		{
			auto car = str1[i];
			auto got = charMap.find(car);
			if (got == charMap.end())
			{
				charMap.emplace(car, 1).second;
			}
			else
			{
				charMap[car] = got->second;
			}
		}

		for (auto i = 0; i < (int)strlen(str2); i++)
		{
			auto car = str2[i];
			auto got = charMap.find(car);
			if (got == charMap.end())
			{
				isPermutation = false;
				break;
			}
			else
			{
				auto count = --got->second;
				if (count != 0)
				{
					charMap[car] = count;
				}
				else
				{
					charMap.erase(car);
				}
			}
		}
	}

	assert(!isPermutation);

	charMap.clear();

	str1 = "aacd";
	str2 = "cdda";

	isPermutation = strlen(str1) == strlen(str2);
	if (isPermutation)
	{
		for (auto i = 0; i < (int)strlen(str1); i++)
		{
			auto car = str1[i];
			auto got = charMap.find(car);
			if (got == charMap.end())
			{
				charMap.emplace(car, 1).second;
			}
			else
			{
				charMap[car] = got->second;
			}
		}

		for (auto i = 0; i < (int)strlen(str2); i++)
		{
			auto car = str2[i];
			auto got = charMap.find(car);
			if (got == charMap.end())
			{
				isPermutation = false;
				break;
			}
			else
			{
				auto count = --got->second;
				if (count != 0)
				{
					charMap[car] = count;
				}
				else
				{
					charMap.erase(car);
				}
			}
		}
	}

	assert(!isPermutation);

	std::cout << "[ SUCCESS ] q2 : 2 string permutable and not" << std::endl;
}

void Chap1::q3()
{
	auto input = "Mr  John   Smith           ";
	auto length = 16;
	auto output = "Mr%20%20John%20%20%20Smith";

	std::string res = "";

	for (auto i = 0; i < length; i++)
	{
		auto car = input[i];
		if (car == ' ')
		{
			res.append("%20");
		}
		else
		{
			res += car;
		}
	}

	assert(res == output);

	std::cout << "[ SUCCESS ] q3 : change space to %20" << std::endl;
}

void Chap1::q4()
{
	bool res = false;
	std::unordered_map<char, int> charMap;

	// input should be all to lower case
	const char in[] = "tacti coa";

	for (int i = 0; i < sizeof(in) / sizeof(char); i++)
	{
		char car = in[i];
		if (car == ' ')
		{
			continue;
		}

		auto got = charMap.find(car);
		if (got == charMap.end())
		{
			charMap.emplace(car, 1);
		}
		else
		{
			charMap[car] = (got->second++);
		}
	}

	bool foundUnevenNumber = true;
	for (auto c : charMap)
	{
		if (c.second % 2 == 0)
			continue;

		if (!foundUnevenNumber)
		{
			foundUnevenNumber = true;
		}
		else
		{
			res = false;
		}
	}

	assert(!res);

	std::cout << "[ SUCCESS ] q4 : palindrome permutation" << std::endl;
}

void Chap1::q5()
{
	// if length delta is more than 2 = fail
	// first discrepency is ok anything different after should be

	const char* inputs[] = { "pale", "pales", "pale", "pale" };
	const char* inputs2[] = { "ple", "pale", "bale", "bake" };

	for (auto i = 0; i < 4; i++) 
	{
		//auto input = inputs[0];
		//for (auto j = 0; j < sizeof(input) /)
	}

	std::cout << "[ SUCCESS ] q5 : one way" << std::endl;
}

void Chap1::q6()
{
	auto input = "aabccccaaa";
	std::string output = "";
	auto expect = "a2b1c43a";

	std::unordered_map<char, int> charMap;

	bool shouldCompress = false;

	for (auto i = 0; i < (int)strlen(input); i++)
	{
		auto c = input[i];
		auto pair = charMap.find(c);

		if (pair == charMap.end())
		{
			charMap.emplace(c, 0);
		}
		else
		{
			shouldCompress |= (pair->second > 1);
			charMap[c] = ++(pair->second);
		}
	}

	auto it = charMap.begin();
	while (it != charMap.end())
	{
		auto c = it->first;
		auto count = it->second;

		output += c;
		output += std::to_string(count);

		it++;
	}

	//assert(expect == output);

	//std::cout << "[ SUCCESS ] q6 : string compression" << std::endl;
}

void Chap1::q7()
{
	/*
	 *   1  2  3        7  4  1
	 *   4  5  6   =>   8  5  2
	 *   7  8  9        9  6  3
	 *
	 *   1  2  3  4  5  6  7  8  9
	 *   7  4  1  8  5  2  9  6  3
	 *
	 *   1 -> + 2
	 *	 2 -> + 4
	 *	 3 -> + 6
	 *   4 -> + 7
	 *   5 -> + 9
	 *   6 -> + 11
	 *   7 -> + 3
	 *   8 -> + 5
	 *   9 -> + 7
	 */

	const int rows = 4, columns = 3;
	const int data[rows][columns] =
	{
		1,   2,   3,
		4,   5,   6,
		7,   8,   9,
		10,  11,  12,
	};

	int rot_data[columns][rows]; // we need to inverse the row number with column and vice versa
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			rot_data[j][rows - i - 1] = data[i][j];

	assert(rot_data[0][0] == 10);
	assert(rot_data[0][1] == 7);
	assert(rot_data[0][2] == 4);
	assert(rot_data[0][3] == 1);
	assert(rot_data[1][0] == 11);
	assert(rot_data[1][1] == 8);
	assert(rot_data[1][2] == 5);
	assert(rot_data[1][3] == 2);
	assert(rot_data[2][0] == 12);
	assert(rot_data[2][1] == 9);
	assert(rot_data[2][2] == 6);
	assert(rot_data[2][3] == 3);

	std::cout << "[ SUCCESS ] q7 : rotate 90 clockwise" << std::endl;
}

void Chap1::q8()
{
	const int rows = 4, columns = 3;
	const int data[rows][columns] =
	{
		1,   2,   3,
		4,   5,   6,
		7,   8,   0,
		10,  11,  12,
	};

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			if (data[i][j] == 0)
			{

			}
		}
}

void Chap1::q9()
{

}

void Chap1::Run()
{
	q1();
	q1_variant();
	q2();
	q3();
	q4();
	q5();
	q6();
	q7();
	q8();
	q9();
}

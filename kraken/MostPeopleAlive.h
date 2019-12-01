#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

struct People
{
	int myBdayYear = -1;
	int myDeathYear = -1;

	People(int aBdayYear, int aDeathYear)
	{
		myBdayYear = aBdayYear;
		myDeathYear = aDeathYear;
	}
};

class MostPeopleAlive 
{
public:
	
	int YearWithMostPeople(vector<People> people)
	{
		typedef int year;
		typedef int count;

		unordered_map<year, count> yearMap;

		for (auto& person : people) 
		{
			for (int i = person.myBdayYear; i <= person.myDeathYear; i++)
			{
				auto found = yearMap.find(i);
				if (found != yearMap.end()) 
				{
					++((*found).second);
				}
				else
				{
					yearMap.emplace(i, 1);
				}

			}
		}

		int highestYear = 0, highestYearCount = 0;

		for (auto& y : yearMap) 
		{
			if (y.second > highestYearCount) 
			{
				highestYear = y.first;
				highestYearCount = y.second;
			}
		}

		return highestYear;
	}
};
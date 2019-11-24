#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


/**
 * ThreeSum leetcode
 * 
 *  vector<int> vec = { -13, 11, 11, 0, -5, -14, 12, -11, -11, -14, -3, 0, -3, 12, -1, -9, -5, -13, 9, -7, -2, 9, -1, 4, -6, -13, -7, 10, 10, 9, 7, 13, 5, 4, -2, 7, 5, -13, 11, 10, -12, -14, -5, -8, 13, 2, -2, -14, 4, -8, -6, -13, 9, 8, 6, 10, 2, 6, 5, -10, 0, -11, -12, 12, 8, -7, -4, -9, -13, -7, 8, 12, -14, 10, -10, 14, -3, 3, -15, -14, 3, -14, 10, -11, 1, 1, 14, -11, 14, 4, -6, -1, 0, -11, -12, -14, -11, 0, 14, -9, 0, 7, -12, 1, -6 };
 *  threeSum(vec);
 */
class ThreeSum 
{
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int>> groups;
		unordered_map<int, int> numsMap;
		set<string> foundGroups;

		if (nums.size() < 3) return groups;

		// we reduce the vector and calculate the count of each value
		for (int m = 0; m < nums.size(); ++m)
		{
			auto kv = numsMap.find(nums[m]);
			if (kv == numsMap.end())
				numsMap.emplace(nums[m], 1);
			else
				++(kv->second);
		}

		{
			// special case
			if (numsMap.size() == 2)
			{
				auto f = numsMap.begin();
				auto s = next(f);

				if (((f->first * 2) + s->first) == 0 && f->second >= 2)
					groups.push_back({ f->first, f->first, s->first });

				if ((f->first + (s->first * 2)) == 0 && s->second >= 2)
					groups.push_back({ f->first, s->first, s->first });

				return groups;
			}
			else if (numsMap.size() == 1)
			{
				auto f = numsMap.begin();
				if (f->first == 0 && f->second >= 3)
					groups.push_back({ 0, 0, 0 });

				return groups;
			}
		}

		// we iterate over a limited set of numbers but also the +1 for the second loop is very important
		// this allows to go from O(N) to O(nlogn)
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {

				int y = nums[j];
				int x = nums[i];

				auto kvInverseDelta = numsMap.find((x + y) * -1);
				if (kvInverseDelta == numsMap.end()) continue;

				int z = kvInverseDelta->first;

				// we need to validate that we have enough "available" values
				auto fiCount = numsMap.find(nums[i])->second;
				auto fjCount = numsMap.find(nums[j])->second;

				if (x == y && fiCount < 2) continue;
				if (y == z && fjCount < 2) continue;
				if (x == z && fiCount < 2) continue;
				if (x == y && x == z && fiCount < 3) continue;

				// we sort the sequence of number to allow variable permutation eg. 123 == 132 == 213 == 231 == 312 == 321
				vector<int> a = { x, y, z };
				sort(a.begin(), a.end());

				string key = to_string(a[0]) + to_string(a[1]) + to_string(a[2]);
				if (foundGroups.find(key) == foundGroups.end())
				{
					groups.push_back(a);
					foundGroups.emplace(key);
				}
			}
		}

		return groups;
	}
};
#pragma once

#include <string>
#include <vector>

using namespace std;

class LargestRectangleHistogram 
{
public:
	class Containment
	{
	public:
		int sIdx = -1;
		int lIdx = -1;
		int height = 0;

		int result()
		{
			if (sIdx == -1 || lIdx == -1) return -1;
			return ((lIdx + 1) - sIdx) * height;
		}
	};

	int findStartOfLowerContainment(vector<int>& heights, int startIdx)
	{
		for (int i = startIdx; i >= 0; --i)
		{
			if (heights[i] >= heights[startIdx]) continue;
			else return i;
		}

		return 0;
	}

	int largestRectangleArea(vector<int>& heights) {

		if (heights.size() == 0) return 0;

		vector<Containment> containments;

		for (int i = 0; i < heights.size(); ++i)
		{
			auto height = heights[i];

			Containment containment;
			containment.sIdx = findStartOfLowerContainment(heights, i);
			containment.height = height;
			containments.push_back(containment);

			for (auto& c : containments)
			{
				if (c.result() != -1) continue;

				if (c.height > height)
					c.lIdx = i;

				if (i == (heights.size() - 1) && c.result() == -1)
					c.lIdx = (heights.size() - 1);
			}
		}

		Containment highestContainment = containments[0];
		for (auto c : containments)
			if (c.result() > highestContainment.result())
				highestContainment = c;

		return highestContainment.result();
	}
};

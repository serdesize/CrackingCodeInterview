#pragma once

#include <functional>
#include <iostream>

/***************************************************************************************************************************
 * Time Complexity -- HashTable information
 * Access : n/a
 * Search : O(1)
 * Insert : O(1)
 * Delete : O(1)
 *
 * The worst case scneario is O(N)
 ***************************************************************************************************************************
 */

namespace ds
{
	using uint = unsigned int;

	template <class K, class V>
	class hash_table
	{

	private:
		static const uint kDefaultSize = 100;

		uint mySize;
		V** myBuffer;

		void resizeBuffer(uint aSize) 
		{
			V** buffer = new V*[aSize];

			std::memcpy(buffer, myBuffer, mySize * sizeof(V));

			delete[] myBuffer;

			myBuffer = buffer;
			mySize = aSize;
		}

		/// -------------------------------------------------------------------
		/// note: This hash function will only work with a few Types that are
		///       supported by the std. 
		///       
		///       bool, char, signed char, unsigned char, char8, char16, char32
		///       wchar, short, wchar, short, unsigned short, int, unsinged int
		///       long, long long, unsigned long, unsigned long long, float
		///       double, long double
		///       
		///       For a custom class, you need specialise the operator function
		///       https://en.cppreference.com/w/cpp/utility/hash
		/// return:
		/// -------------------------------------------------------------------
		int computeIdx(K aKey)
		{
			std::hash<K> ptrHash;	
			int idx = ptrHash(aKey) % mySize;

			// TODO : handle collision

			// we dont handle collision, but there is a few other methodology
			//  - Seperate Chaining 
			//  - Open Addressing 
			//  - Perfect Hashing (need to know all the keys beforhand)

			return idx;
		}

	public:

		/// -------------------------------------------------------------------
		/// note:
		/// return:
		/// -------------------------------------------------------------------
		hash_table<K, V>(uint aSize = kDefaultSize)
			: mySize(aSize)
		{
			if (aSize != kDefaultSize)
			{
				delete[] myBuffer;
		
				V** buffer = new V*[aSize];
				myBuffer = buffer;
			}

			myBuffer = new V* [kDefaultSize];
		}

		~hash_table()
		{ 
			mySize = 0;
			myBuffer = nullptr;
		}

		/// -------------------------------------------------------------------
		/// note:
		/// return:
		/// -------------------------------------------------------------------
		bool add(K aKey, V* aValue)
		{
			uint idx = computeIdx(aKey);

			if (idx > mySize) 
			{
				resizeBuffer(mySize * 2);
				idx = computeIdx(aKey);
			}

			myBuffer[idx] = aValue;

			return true;
		}
		/// -------------------------------------------------------------------

		/// -------------------------------------------------------------------
		/// note:
		/// return:
		/// -------------------------------------------------------------------
		bool remove(K aKey)
		{
			int idx = computeIdx(aKey);
			myBuffer[idx] = nullptr;
			return false;
		}
		/// -------------------------------------------------------------------

		/// -------------------------------------------------------------------
		/// note:
		/// return:
		/// -------------------------------------------------------------------
		V* get(K aKey) 
		{
			int idx = computeIdx(aKey);
			return myBuffer[idx];
		}
		/// -------------------------------------------------------------------
	};
};
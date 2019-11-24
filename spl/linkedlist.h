#pragma once

#include "node.h"

/***************************************************************************************************************************
 * Time Complexity -- LinkedList information  
 * Access : O(N)
 * Search : O(N)
 * Insert : O(1)
 * Delete : O(1)
 *
 * My implementation for delete and insert @ index, thus it need to traverse the linked list so it would be O(n) for both
 * actions. The worst case for all actions is O(N), but normally we should have insert and delete O(1)
 ***************************************************************************************************************************
 */

namespace ds
{
	using uint = unsigned int;

	template <class T>
	class linkedlist
	{
	private:
		node::node<T>* root;

	public:
		linkedlist()
			: root( nullptr )
		{ }

		~linkedlist() { root = nullptr; }

		/// -------------------------------------------------------------------
		/// note: index is 0 base 
		/// return: true if able to add, false otherwise
		/// -------------------------------------------------------------------
		bool add( T aData, uint aIndex ) noexcept
		{
			if ( root == nullptr )
				return false;

			uint counter = 0;
			auto previous = root;
			auto node = root->get_LeftNode();
			while ( node != nullptr )
			{
				if (aIndex == counter)
				{
					return previous->set_LeftNode( new node::node<int>( aData, node ) );
				}

				previous = node;
				node = node->get_LeftNode();

				counter++;
			}

			return false;
		}
		/// -------------------------------------------------------------------
	
		enum class PositionInsert
		{
			End = 0,
			Beginning
		};

		/// -------------------------------------------------------------------
		/// note: add aData to the end of the linked list
		/// return: true if able to add
		/// -------------------------------------------------------------------
		bool add( T aData, PositionInsert pos = PositionInsert::End ) noexcept
		{
			if ( root == nullptr )
			{
				root = new node::node<T>( aData );
				return true;
			}

			// add node to root and push the root down
			if ( pos == PositionInsert::Beginning )
			{
				auto tmpNode = root;
				root = new node::node<T>( aData );
				root->set_LeftNode( tmpNode );
				
				return true;
			}

			// add node to tail
			auto previous = root;
			auto node = root->get_LeftNode();
			while (node != nullptr)
			{
				previous = node;
				node = node->get_LeftNode();
			}

			previous->set_LeftNode(new node::node<T>( aData ));

			return true;
		}
		/// -------------------------------------------------------------------

		/// -------------------------------------------------------------------
		/// note:
		/// return:
		/// -------------------------------------------------------------------
		bool contains( T aData )
		{
			if ( root == nullptr )
				return false;

			auto node = root->get_LeftNode();
			while( node != nullptr )
			{
				// this is probably wrong because the address might be right
				// but maybe the memory is different
				if ( node->get_Data() == aData )
				{
					return true;
				}

				node = node->get_LeftNode();
			}

			return false;
		}
		/// -------------------------------------------------------------------

		/// -------------------------------------------------------------------
		/// note:
		/// return:
		/// -------------------------------------------------------------------
		bool remove( int index ) noexcept 
		{
			if ( root == nullptr )
				return false;

			if ( index == 0 ) 
			{
				root = root->get_LeftNode();
				return true;
			}

			int count = 0;
			auto node = root;
			auto nextNode = root->get_LeftNode();

			while ( count < index )
			{
				count++;

				if ( count == index )
				{
					return node->set_LeftNode( nextNode->get_LeftNode() );
				}

				node = nextNode;
				nextNode = node->get_LeftNode();

				if ( nextNode == nullptr ) 
				{
					return false;
				}
			}

			return false;
		}
		/// -------------------------------------------------------------------
	};
}



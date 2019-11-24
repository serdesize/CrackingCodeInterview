#pragma once

#include "node.h"

/***************************************************************************************************************************
 * Time Complexity -- BST information
 * Access : O(log(N))
 * Search : O(log(N))
 * Insert : O(log(N))
 * Delete : O(log(N))
 *
 ***************************************************************************************************************************
 */

namespace ds 
{
	template <class T>
	class bstree
	{
	private:
		node::node<T>* myRoot;

	public:
		bstree() : myRoot(nullptr) { }
		~bstree() { myRoot = nullptr; }

		/// -------------------------------------------------------------------
		/// note: Will add a new generic item to the tree
		/// time complexity: O(log N)
		/// return:
		/// -------------------------------------------------------------------
		bool add(T anItem)
		{ 
			node::node<T>* current = myRoot;
			while (current != nullptr) 
			{
				if (anItem < current->get_Data()) 
				{
					if (current->get_LeftNode())
						current = current->get_LeftNode();
					else 
					{
						current->set_LeftNode(new node::node<T>(anItem));
						return true;
					}
				}
				else 
				{
					if (current->get_RightNode())
						current = current->get_RightNode();
					else
					{
						current->set_RightNode(new node::node<T>(anItem));
						return true;
					}
				}
			}

			if (myRoot == nullptr)
				myRoot = new node::node<T>(anItem);

			return true;
		}

		/// -------------------------------------------------------------------
		/// note: Will set the parent node to nullptr and 
		/// time complexity: O(log N)
		/// return:
		/// -------------------------------------------------------------------
		bool remove(T anItem)
		{ 
			node::node<T>* parent = myRoot;
			node::node<T>* current = myRoot;
			while (current != nullptr)
			{
				parent = current;

				bool isFromLeft = false;

				if (anItem < current.get_Data()) 
				{
					isFromLeft = true;
					current = current->get_LeftNode();
				}
				else 
					current = current->get_RightNode();

				if (current.get_Data() == anItem)
				{
					// delete the node
					if (isFromLeft) parent->set_LeftNode(nullptr);
					else parent->set_RightNode(nullptr);

					// add left branch
					if (current->get_LeftNode())
						add(current->get_LeftNode()->get_Data());

					// add right branch
					if (current->get_RightNode())
						add(current->get_RightNode()->get_Data());

					return true;
				}
			}

			return false; 
		}
		
		/// -------------------------------------------------------------------
		/// note: 
		/// time complexity: O(log N)
		/// return:
		/// -------------------------------------------------------------------
		node::node<T>* find(T anItem)
		{
			node::node<T>* current = myRoot;
			while (current != nullptr)
			{
				if (anItem < current->get_Data())
					current = current->get_LeftNode();
				else
					current = current->get_RightNode();

				if (current != nullptr && current->get_Data() == anItem) return current;
			}

			return nullptr;
		}
	};
}
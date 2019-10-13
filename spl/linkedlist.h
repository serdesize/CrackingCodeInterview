#pragma once

namespace ds 
{
	using uint = unsigned int;

	template <class T>
	class node
	{
	private:
		node* myNextNode;
		T myData;

	public:
		node(T aData, node* aNextNode = nullptr)
			: myData(aData)
			, myNextNode(aNextNode)
		{ }

		~node() { myNextNode = nullptr; }

		node* getNextNode() const
		{
			return myNextNode;
		}

		/// -------------------------------------------------------------------
		/// note: 
		/// return: true if able to set the new generic element, false otherwise
		/// -------------------------------------------------------------------
		bool setNextNode(node* aNode) noexcept
		{
			if (aNode == nullptr)
				return false;

			myNextNode = aNode;
			return true;
		}
		/// -------------------------------------------------------------------
	
		/// -------------------------------------------------------------------
		/// note:
		/// return:
		/// -------------------------------------------------------------------
		T getData() const noexcept
		{
			return myData;
		}
		/// -------------------------------------------------------------------
	};

	template <class T>
	class linkedlist
	{
	private:
		node<T>* root;

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
			auto node = root->getNextNode();
			while ( node != nullptr )
			{
				if (aIndex == counter)
				{
					return previous->setNextNode( new ds::node<int>( aData, node ) );
				}

				previous = node;
				node = node->getNextNode();

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
				root = new node<T>( aData );
				return true;
			}

			// add node to root and push the root down
			if ( pos == PositionInsert::Beginning )
			{
				auto tmpNode = root;
				root = new node<T>( aData );
				root->setNextNode( tmpNode );
				
				return true;
			}

			// add node to tail
			auto previous = root;
			auto node = root->getNextNode();
			while (node != nullptr)
			{
				previous = node;
				node = node->getNextNode();
			}

			previous->setNextNode(new ds::node<T>( aData ));

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

			auto node = root->getNextNode();
			while( node != nullptr )
			{
				// this is probably wrong because the address might be right
				// but maybe the memory is different
				if ( node->getData() == aData )
				{
					return true;
				}

				node = node->getNextNode();
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
				root = root->getNextNode();
				return true;
			}

			int count = 0;
			auto node = root;
			auto nextNode = root->getNextNode();

			while ( count < index )
			{
				count++;

				if ( count == index )
				{
					return node->setNextNode( nextNode->getNextNode() );
				}

				node = nextNode;
				nextNode = node->getNextNode();

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



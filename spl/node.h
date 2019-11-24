#pragma once

namespace node 
{
	template <class T>
	class node
	{
	private:
		node* left_node;
		node* right_node;
		T myData;

	public:
		node(T aData, node* aLeftNode = nullptr, node* aRightNode = nullptr)
			: myData(aData)
			, left_node(aLeftNode)
			, right_node(aRightNode)
		{ }

		~node() { left_node = nullptr; right_node = nullptr; }

		node* get_LeftNode() const
		{
			return left_node;
		}

		node* get_RightNode() const 
		{
			return right_node;
		}

		/// -------------------------------------------------------------------
		/// note: 
		/// return: true if able to set the new generic element, false otherwise
		/// -------------------------------------------------------------------
		bool set_LeftNode(node* aNode) noexcept
		{
			if (aNode == nullptr) 
				delete left_node;
			else
				left_node = aNode;
	
			return true;
		}
		/// -------------------------------------------------------------------

		bool set_RightNode(node* aNode) noexcept 
		{
			if (aNode == nullptr)
				delete right_node;
			else
				right_node = aNode;

			return true;
		}

		/// -------------------------------------------------------------------
		/// note:
		/// return:
		/// -------------------------------------------------------------------
		T get_Data() const noexcept
		{
			return myData;
		}
		/// -------------------------------------------------------------------
	};
}
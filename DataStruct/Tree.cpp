#include <iostream>
#include <vector>
using namespace std;

//namespace BT_by_array
//{
//	class BT
//	{
//	private:
//		vector<int> nodes;
//
//	public:
//		BT(int node_size, int root_data)
//		{
//			nodes.resize(node_size);
//			nodes[0] = root_data;
//		}
//
//		void set_left(int data, int parent_idx)
//		{
//			nodes[parent_idx * 2 + 1] = data;
//		}
//
//		void set_right(int data, int parent_idx)
//		{
//			nodes[parent_idx * 2 + 2] = data;
//		}
//
//		void PrintTree()
//		{
//			for (auto& node : nodes)
//			{
//				std::cout << node << " ";
//			}
//			std::cout << std::endl;
//		}
//
//	};
//
//	int main()
//	{
//		BT bst(7, 0);
//		bst.set_left(1, 0);
//		bst.set_right(2, 0);
//
//		bst.set_left(3, 1);
//		bst.set_right(4, 1);
//
//		bst.set_left(5, 2);
//		bst.set_right(6, 2);
//
//		bst.PrintTree();
//		return 0;
//	}
//}

namespace BT_by_List
{
	class Binary_Search_Tree
	{
	private:
		struct Node
		{
			int data;
			Node* left;
			Node* right;
			Node(int data) : data(data), left(nullptr), right(nullptr) {}
		};

		void _insert(Node* cusor, int data)
		{
			Node* parent(0);
			while (cusor)
			{
				parent = cusor; //값이 들어있는 단말 노드의 마지막으로 가기 위함
				if (parent->data < data)
				{
					cusor = cusor->right;
				}
				else if (parent->data > data)
				{
					cusor = cusor->left;
				}

				else
				{
					cout << "이미 있는 값입니다. " << endl;
					return;
				}
			}

			if (parent->data < data)
			{
				parent->right = new Node(data);
			}
			else
			{
				parent->left = new Node(data);
			}
		}

		void _inorder(Node* cusor)
		{
			if (!cusor) return;

			_inorder(cusor->left);
			cout << cusor->data << " ";
			_inorder(cusor->right);
		}


		Node* root;
	public:
		Binary_Search_Tree() : root(nullptr) {}

		void insert(int data)
		{
			if (!root)
			{
				root = new Node(data);
				return;
			}

			_insert(root, data);
		}

		void _inorder()
		{
			_inorder(root);
		}

	};

	int main()
	{
		Binary_Search_Tree bst;
		bst.insert(30);
		bst.insert(40);
		bst.insert(10);
		bst.insert(20);
		bst._inorder();
	}
}


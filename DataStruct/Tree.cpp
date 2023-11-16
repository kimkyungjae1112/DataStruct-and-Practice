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
    struct TreeNode
    {
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    // ���� Ʈ�� Ŭ����
    class BinaryTree
    {
    private:
        TreeNode* root;

        // ��������� inorder ��ȸ�� �����ϴ� helper �Լ�
        void inorderHelper(TreeNode* node)
        {
            if (node)
            {
                inorderHelper(node->left);
                cout << node->data << " ";
                inorderHelper(node->right);
            }
        }

        void preorderHelper(TreeNode* node)
        {
            if (node)
            {
                cout << node->data << " ";
                preorderHelper(node->left);
                preorderHelper(node->right);
            }
        }

    public:
        BinaryTree() : root(nullptr) {}

        // �� ��带 �߰��ϴ� �Լ�
        TreeNode* insert(TreeNode* node, int data)
        {
            if (node == nullptr)
            {
                return new TreeNode(data);
            }

            if (data < node->data)
            {
                node->left = insert(node->left, data);
            }
            else if (data > node->data)
            {
                node->right = insert(node->right, data);
            }

            return node;
        }

        // ���� Ʈ���� �� �����͸� �߰��ϴ� �Լ�
        void addNode(int data)
        {
            root = insert(root, data);
        }

        // inorder ��ȸ�� ȣ���ϴ� �Լ�
        void inorderTraversal()
        {
            inorderHelper(root);
        }

        void preorder()
        {
            preorderHelper(root);
        }
    };

    int main()
    {
        BinaryTree tree;

        // ���� Ʈ���� ��� �߰�
        tree.addNode(5);
        tree.addNode(3);
        tree.addNode(7);
        tree.addNode(2);
        tree.addNode(4);

        // inorder ��ȸ ���
        cout << "Inorder Traversal: ";
        tree.inorderTraversal();
        cout << endl;
        cout << "preorder Traversal: ";
        tree.preorder();

        return 0;
    }
}

class Binary_Tree
{
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(int data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void inorder_help(Node* start)
    {
        if (start)
        {
            inorder_help(start->left);
            cout << start->data << " ";
            inorder_help(start->right);
        }
    }
public:
    Binary_Tree() : root(nullptr) {}

    Node* insert(Node* start, int data)
    {
        if (start == nullptr)
        {
            return new Node(data);
        }
        else if (data < start->data)
        {
            return insert(start->left, data);
        }
        else if (data > start->data)
        {
            return insert(start->right, data);
        }
        return start;
    }

    void add_node(int data)
    {
        Node* current = root;
        current = insert(current, data);
    }

    void inorder()
    {
        inorder_help(root);
    }
};

int main()
{
    Binary_Tree bt;
    bt.add_node(1);
    bt.add_node(6);
    bt.add_node(3);
    bt.add_node(2);
    bt.add_node(4);
    bt.add_node(5);
    bt.inorder();
}
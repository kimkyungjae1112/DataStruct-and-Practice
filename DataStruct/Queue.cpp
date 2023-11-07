//#include <iostream>
//
//class Queue
//{
//	int Q[16];
//	int Head;
//	int Tail;
//
//public:
//	Queue() : Head(0), Tail(0) {}
//	
//	bool is_full()
//	{
//		if (((Tail + 1) % 16) == Head) return true;
//		else return false;
//	}
//
//	bool is_empty()
//	{
//		if (Head == Tail) return true;
//		else return false;
//	}
//
//	void enqueue(int data)
//	{
//		if (!is_full())
//		{
//			Q[Tail] = data;
//			Tail = (Tail + 1) % 16;
//		}
//		else return;
//	}
//
//	int dequeue()
//	{
//		if (!is_empty())
//		{
//			int p = Q[Head];
//			Head = (Head + 1) % 16;
//			return p;
//		}
//		else return -1;
//	}
//};
//
//int main()
//{
//	Queue Q;
//	for (int i = 0; i < 50; ++i)
//	{
//		if (Q.is_empty())
//			Q.enqueue(i);
//
//		else
//			std::cout << Q.dequeue() << std::endl; 
//	}
//}
//

#include <iostream>

template <typename T>
class Queue
{
	struct Node
	{
		T data;
		Node* next;
		Node(T data) : data(data), next(nullptr) {}
	};

	Node* head, * tail;

public:
	Queue() : head(nullptr), tail(nullptr) {}

	bool is_empty()
	{
		if (tail == nullptr) return true;
		return false;
	}

	void enqueue(T data)
	{
		Node* new_node = new Node(data);
		if (is_empty())
		{
			head = tail = new_node;
			return;
		}
		tail->next = new_node;
		tail = new_node;
	}

	T dequeue()
	{
		if (!is_empty())
		{
			Node* temp = head;
			head = head->next;
			T data = temp->data;
			delete temp;
			return data;
		}
		else
		{
			std::cout << "Q가 비어있다." << std::endl;
			return NULL;
		}
	}

	T peek()
	{
		return head->data;
	}
};

int main()
{
	Queue<int> Q;
	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);

	std::cout << Q.peek() << std::endl;
	std::cout << Q.dequeue() << std::endl;
	std::cout << Q.dequeue() << std::endl;
	std::cout << Q.dequeue() << std::endl;
	std::cout << Q.dequeue() << std::endl;
}

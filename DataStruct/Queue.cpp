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

//#include <iostream>
//
//class Queue
//{
//	struct Node
//	{
//		int data;
//		Node* next;
//		Node(int data) : data(data), next(nullptr) {}
//	};
//
//	Node* head, *tail;
//public:
//	Queue() : head(nullptr), tail(nullptr){}
//	void push(int data)
//	{
//		Node* new_node = new Node(data);
//		if (head == nullptr && tail == nullptr)
//		{
//			head = tail = new_node;
//			return;
//		}
//		tail->next = new_node;
//		tail = new_node;
//	}
//
//	int pop()
//	{
//		Node* temp = head;
//		head = head->next;
//		int data = temp->data;
//		delete temp;
//		return data;
//	}
//};
//
//int main()
//{
//	Queue Q;
//	Q.push(10);
//	Q.push(20);
//	Q.push(30);
//	std::cout << Q.pop() << std::endl;
//	std::cout << Q.pop() << std::endl;
//}
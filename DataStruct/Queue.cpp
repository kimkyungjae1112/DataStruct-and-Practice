#include <iostream>

namespace circute_queue_by_array
{
	template <typename T>
	class Queue
	{
		T queue;
		int Head;
		int Tail;

	public:
		Queue() : Head(0), Tail(0) {}

		bool is_full()
		{
			if (((Tail + 1) % 16) == Head) return true;
			else return false;
		}

		bool is_empty()
		{
			if (Head == Tail) return true;
			else return false;
		}

		void enqueue(int data)
		{
			if (!is_full())
			{
				queue[Tail] = data;
				Tail = (Tail + 1) % 16;
			}
			else return;
		}

		int dequeue()
		{
			if (!is_empty())
			{
				int p = queue[Head];
				Head = (Head + 1) % 16;
				return p;
			}
			else return -1;
		}
	};
}


namespace queue_by_sll
{

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
}

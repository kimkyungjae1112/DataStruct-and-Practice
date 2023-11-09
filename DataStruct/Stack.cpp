#include <iostream>

namespace stack_by_array
{
	template<typename T>
	class Stack
	{
		T* stack;
		int stack_point;

		int memory_allocation;

	public:
		Stack() : stack_point(-1), stack(new T[1]), memory_allocation(1) {}
		Stack(int size) : stack_point(-1), stack(new T[size]), memory_allocation(size) {}

		bool is_full()
		{
			if (stack_point >= 1) return true;
			return false;
		}

		bool is_empty()
		{
			if (stack_point == -1) return true;
			return false;
		}
		void push(T data)
		{
			if (stack_point >= memory_allocation)
			{
				T* temp = new T[memory_allocation * 2];
				for (int i = 0; i < stack_point; ++i)
				{
					temp[i] = stack[i];
				}
				delete[] stack;
				stack = temp;
				memory_allocation *= 2;

			}
			stack[++stack_point] = data;
		}

		void pop()
		{
			if (!is_empty()) stack[stack_point--];
			else return;
		}

		T top()
		{
			if (!is_empty()) return stack[stack_point];
			else return -1;
		}

		void print()
		{
			int current_point = stack_point;
			while (!is_empty())
			{
				std::cout << top() << std::endl;
				pop();
			}
			stack_point = current_point;
		}

	};
}

namespace stack_by_sll
{
	template<typename T>
	class Stack
	{
		struct Node
		{
			T data;
			Node* next;
			Node(T data) : data(data), next(nullptr) {}
		};

		Node* head;

	public:
		Stack() : head(nullptr) {}
		void push(T data)
		{
			Node* new_node = new Node(data);
			new_node->next = head;
			head = new_node;
		}

		void pop()
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}

		T top()
		{
			return head->data;
		}

		void print()
		{
			Node* current = head;
			while (current != nullptr)
			{
				std::cout << current->data << std::endl;
				current = current->next;
			}
		}

		bool empty()
		{
			if (head == nullptr) return true;
			else return false;
		}
	};
}


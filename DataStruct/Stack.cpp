#include <iostream>

namespace stack_by_array
{
	template<typename T>
	class Stack
	{
		T* stack;
		int stack_point;

		int memory_allocation;
		int length;
	public:
		Stack() : stack_point(-1), stack(new T[1]), memory_allocation(1), length(0) {}
		Stack(int size) : stack_point(-1), stack(new T[size]), memory_allocation(size), length(0) {}

		bool is_full()
		{
			return stack_point >= memory_allocation - 1; // 수정: 스택이 가득 찼는지 확인하는 조건 수정
		}

		bool is_empty()
		{
			if (stack_point == -1) return true;
			return false;
		}

		void push(T data)
		{
			if (stack_point + 1 >= memory_allocation)
			{
				T* temp = new T[memory_allocation * 2];
				for (int i = 0; i <= stack_point; ++i)
				{
					temp[i] = stack[i];
				}
				delete[] stack;
				stack = temp;
				memory_allocation *= 2;
			}
			stack[++stack_point] = data;
			length++;
		}

		void pop()
		{
			if (!is_empty())
			{
				stack_point--;
				length--;
			}
			else return;
		}

		T top()
		{
			if (!is_empty()) return stack[stack_point];
			else return -1;
		}

		void print() const
		{
			for (int i = stack_point; i >= 0; --i)
			{
				std::cout << stack[i] << std::endl;
			}
		}

		int get_length()
		{
			return length;
		}
		
		int get_capacity()
		{
			return memory_allocation;
		}

		~Stack()
		{
			delete[] stack;
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

		int length;

		Node* head;

	public:
		Stack() : head(nullptr), length(0) {}
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

		int get_length()
		{
			Node* current = head;
			while (current)
			{
				length++;
				current = current->next;
			}
			return length;
		}
	};
}

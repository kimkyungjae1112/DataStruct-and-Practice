//배열로 스택 구현
//#include <iostream>
//
//class Stack
//{
//	int stack[16];
//	int stack_point;
//
//public:
//	Stack() : stack_point(0) {}
//
//	bool is_full()
//	{
//		if (stack_point >= 16) return true;
//		return false;
//	}
//
//	bool is_empty()
//	{
//		if (stack_point == 0) return true;
//		return false;
//	}
//	void push(int data)
//	{
//		if (!is_full())
//		{
//			stack[stack_point++] = data;
//		}
//		else
//		{
//			return;
//		}
//	}
//	
//	int pop()
//	{
//		if (!is_empty()) return stack[stack_point--];
//		else return -1;
//	}
//
//};

//#include <iostream>
//
//class Stack
//{
//	struct Node
//	{
//		int data;
//		Node* next;
//		Node(int data) : data(data), next(nullptr) {}
//	};
//
//	Node* top;
//
//public:
//	Stack() : top(nullptr) {}
//	void push(int data)
//	{
//		Node* new_node = new Node(data);
//		new_node->next = top;
//		top = new_node;
//	}
//
//	int pop()
//	{
//		Node* temp = top;
//		top = top->next;
//		int value = temp->data;
//		delete temp;
//		return value;
//	}
//	void print()
//	{
//		Node* current = top;
//		while (top != nullptr)
//		{
//			std::cout << top->data << std::endl;
//			top = top->next;
//		}
//	}
//};
//
//int main()
//{
//	Stack st;
//	st.push(10);
//	st.push(20);
//	st.push(30);
//	std::cout << st.pop() << std::endl;
//	std::cout << st.pop() << std::endl;
//	st.push(50);
//	st.push(40);
//	st.print();
//}
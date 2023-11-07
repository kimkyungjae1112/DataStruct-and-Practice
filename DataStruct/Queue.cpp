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

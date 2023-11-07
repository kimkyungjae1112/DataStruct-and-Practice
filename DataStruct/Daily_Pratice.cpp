#include <iostream>
#include <cmath>
using namespace std;

class Heap_Tree
{
	int* heap;
	int length;
	int capacity;
	int round_count;
	bool check;

public:


	Heap_Tree();
	void Add(int data);
	void make_heap_tree();
	void make_heap_tree2();
	void print();
	int get_length();
	int get_capacity();
};

Heap_Tree::Heap_Tree() : heap(new int[10]), length(0), capacity(10), check(false), round_count(0) {}

void Heap_Tree::Add(int data)
{
	if (length >= capacity)
	{
		int* temp = new int[capacity * 2];

		for (int i = 0; i < length; ++i)
		{
			temp[i] = heap[i];
		}
		delete[] heap;
		heap = temp;
		capacity *= 2;
		check = true;
	}

	heap[length++] = data;
	if (check)
	{
		make_heap_tree2();
	}
}

void Heap_Tree::make_heap_tree()
{
	for (int i = 1; i < length; ++i)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (heap[root] < heap[c])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
}

void Heap_Tree::make_heap_tree2()
{
	int c = length - 1;
	do
	{
		int root = (c - 1) / 2;
		if (heap[root] < heap[c])
		{
			if (check)
			{
				print();
				check = !check;
				round_count++;
			}
			int temp = heap[root];
			heap[root] = heap[c];
			heap[c] = temp;
			print();
			round_count++;
		}

		c = root;
	} while (c != 0);


}
void Heap_Tree::print()
{
	int level = 0, a = 0;
	int temp = length;
	while (temp != 0)
	{
		temp /= 2;
		level++;
	}

	int index = 0;
	cout << "Round " << round_count << ": " << endl;;
	for (int i = 0; i < level; ++i)
	{
		for (int k = level * 2 - i * 2; k > 0; --k)
		{
			cout << " ";
		}
		for (int j = 0; j < pow(2, i) && index < length; ++j)
		{
			cout << heap[index++];
			for (int z = level - i; z > 0; --z)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int Heap_Tree::get_length()
{
	return length;
}

int Heap_Tree::get_capacity()
{
	return capacity;
}
int main()
{
	Heap_Tree ht;
	int count = 10;

	int i;
	while (count--)
	{
		cin >> i;
		ht.Add(i);
	}
	ht.make_heap_tree();
	ht.print();
	ht.Add(15);
}
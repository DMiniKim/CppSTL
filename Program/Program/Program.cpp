#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>

class PriorityQueue
{
private:
	int index;
	int capacity;
	T* container;
public:
	PriorityQueue()
	{
		index = 0;
		capacity = 0;
		if (container != nullptr)
		{
			container = nullptr;
		}
	}
	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (capacity <= index)
		{
			resize(capacity * 2);
		}
		container[index++] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				swap(container[parent], container[child]);
			}
			child = parent;
			parent = (child - 1) / 2;
		}

	}
	void resize(int newSize)
	{
		capacity = newSize;

		T* temp = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temp[i] = NULL;
		}
		for (int i = 0; i < index; i++)
		{
			temp[i] = container[i];
		}
		if (container != nullptr)
		{
			delete[] container;
		}
		container = temp;
	}
	const T& top()
	{
		return container[0];
	}
	const bool empty()
	{
		return index <= 0;
	}
	void Print()
	{
		for (int i = 0; i < index; i++)
		{
			cout << container[i] << endl;
		}
	}
	void pop()
	{
		if (empty())
		{
			cout << "암것도 없음" << endl;
			return;
		}
		else
		{
			container[0] = container[--index];
			container[index] = NULL;
			int parent = 0;
			int leftchild = (parent * 2) + 1;
			int Rightchild = (parent * 2) + 2;

			while ((parent * 2 + 1) < index)
			{
				if (container[parent] < container[leftchild])
				{
					swap(container[parent], container[leftchild]);
					parent = leftchild;
				}
				else if (container[parent] < container[Rightchild])
				{
					swap(container[parent], container[Rightchild]);
					parent = Rightchild;
				}
			}
		}
	}
	~PriorityQueue()
	{
		if (container != nullptr)
		{
			delete container;
		}
	}
};



int main()
{
	PriorityQueue<int> pque;
	pque.push(10);
	pque.push(20);
	pque.push(30);
	pque.push(40);
	pque.push(50);
	pque.push(60);
	pque.push(70);
	pque.push(80);
	pque.push(90);
	pque.push(100);
	pque.push(110);




	return 0;
}
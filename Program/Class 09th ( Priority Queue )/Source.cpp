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

			int parent = 0;


			while ((parent * 2 + 1) < index)
			{
				int child = (parent * 2) + 1;
				if (container[child] < container[child + 1]) // 오른쪽 자식의 값이 클 경우 child index 변경
				{
					child++;
				}
				if (container[child] < container[parent]) // 부모가 자식보다 큰 상태라면 냅두기
				{
					break;
				}
				else                                      // 자식이 큰 경우면 바꿔야지
				{
					std::swap(container[child], container[parent]);
					parent = child;							// 그리고 부모 갱신해주기
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

	pque.Print();

	cout << "=================================" << endl;
	while (pque.empty() == false)
	{
		cout << pque.top() << endl;
		pque.pop();
		pque.Print();
		cout << "=================================" << endl;

	}

	return 0;
}
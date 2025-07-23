#include <iostream>
#define SIZE 4

using namespace std;

template <typename T>
class Queue
{
private:
	int front;
	int rear;
	T container[SIZE];
public:
	Queue()
	{
		front = SIZE - 1;
		rear = SIZE - 1;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void push(T data)
	{
		if (front == (rear + 1) % SIZE)
		{
			cout << "꽉 참" << endl;
		}
		else
		{
			rear = (rear + 1) % SIZE;
			container[rear] = data;
		}
	}
	bool empty()
	{
		return front == rear;
	}
	void pop()
	{
		if (empty())
		{
			cout << "Push First" << endl;
		}
		else
		{
			front = (front + 1) % SIZE;
			container[front] = NULL;
		}
	}
	const T& Front()
	{
		if (empty())
		{
			exit(1);
		}
		else
		{
			return container[(front + 1) % SIZE];
		}
	}
};
int main()
{
	Queue<int> que;
	que.push(10);
	que.push(20);
	que.push(30);
	que.push(40);
	return 0;
}
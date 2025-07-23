#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>

class Queue
{
private:

	int front;
	int rear;
	T arr[SIZE];
public:
	Queue()
	{

		front = 0;
		rear = 0;
		for (int i = 0; i < SIZE; i++) arr[i] = NULL;
	}
	void push(T data)
	{
		if (rear >= SIZE)
		{
			cout << "linear queue is overflow" << endl;
		}
		else
		{
			arr[rear++] = data;
		}
		//if (front == rear)
		//{
		//	rear = SIZE;
		//	arr[SIZE - 1] = data;
		//	front = SIZE - 2;
		//}
		//else
		//{
		//
		//}
	}
	bool empty()
	{
		return front == rear;
	}
	void pop()
	{
		if (empty())
		{
			cout << "비어있으니 Push부터 하셈" << endl;
		}
		else
		{
			arr[front++] = NULL;
		}
	}
	const T& Front()
	{
		return (empty()) ? 1 : arr[front];
	}
	const int& size()
	{
		return (rear - front);
	}

};



int main()
{
	Queue<int> que;
	que.push(10);
	que.push(20);
	que.push(30);
	que.push(40);
	que.push(50);
	que.push(10);

	cout << que.size() << endl;

	cout << que.Front() << endl;
	que.pop();
	cout << que.Front() << endl;
	que.pop();
	cout << que.Front() << endl;
	que.pop();
	cout << que.Front() << endl;
	que.pop();
	cout << que.Front() << endl;
	que.pop();
	cout << que.Front() << endl;
	que.pop();

	return 0;
}
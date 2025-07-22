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
	void push()
	{
		if (empty())
		{
			container[rear++];
		}
		else
		{
			container[rear++];
			rear% SIZE;
			if (front == rear)
			{
				front++;
				front% SIZE;
			}
		}
	}
	bool empty()
	{
		return front == rear;
	}
};
int main()
{

	return 0;
}
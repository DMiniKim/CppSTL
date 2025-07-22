#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>

class Stack
{
	int count;
	int highset;
public:
	T arr[SIZE];
	Stack()
	{
		count = 0;
		highset = -1;
		for (int i = 0; i < SIZE; i++) arr[i] = NULL;
	}
	void push(T data)
	{

		if (count < 5)
		{
			highset++;
			arr[highset] = data;
			count++;
		}
		else
		{
			cout << "Stack Overflow" << endl;
		}

	}
	bool empty()
	{
		return count == 0;
	}
	void pop()
	{
		if (highset > -1)
		{
			highset--;
			count--;
		}
		else
		{
			cout << "Stack is Empty" << endl;
		}
	}
	const int& size()
	{
		return count;
	}
	const T& top()
	{
		return (highset > -1) ? arr[highset] : NULL;
	}
};








int main()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);
	cout << "================" << endl;
	cout << st.size() << endl;
	cout << "================" << endl;
	cout << st.empty() << endl;
	cout << "================" << endl;
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();



	return 0;
}
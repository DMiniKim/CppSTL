#include <iostream>

using namespace std;

#define SIZE 10

template<typename T>

class AdjacencyList
{
	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};
	int size;			// 정점 개수
	T vertex[SIZE];		// 정점 집합
	Node* list[SIZE];	// 인접 리스트

public:
	AdjacencyList() :size(0)
	{
		for (int i = 0; i < SIZE; i++)
		{
			list[i] = nullptr;
			vertex[i] = NULL;
		}
	}
	void push(T data)
	{
		if (size > SIZE)
		{
			cout << "AdjacencyList is Overflow" << endl;
		}
		else
		{
			vertex[size++] = data;
		}
	}
	void edge(int i, int j)
	{

		if (size <= 0)
		{
			cout << "Edge List is Empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "index is out of range" << endl;
		}
		else
		{
			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);			
		}
	}
	//~AdjacencyList()
	//{
	//	for (int i = 0; i < SIZE; i++)
	//	{
	//		if (list[i] != nullptr)
	//		{
	//			delete[] list[i];		// 이게 가능한 이유는 포인트 배열이라서 해당 배열에 모든 메모리를 
	//									// delete 할 수 있기 때문이다.
	//		}
	//	}
	//}
};

int main()
{
	AdjacencyList<char> list;
	list.push('A');
	list.push('B');
	list.push('C');
	list.push('D');
	list.edge(0, 1);
	list.edge(3, 2);
	list.edge(1, 3);
	list.edge(0, 3);
	return 0;
}
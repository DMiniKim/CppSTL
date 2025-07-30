#include <iostream>

using namespace std;

#define SIZE 10

template<typename T>

class AdjacencyList
{
private:

	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
		~Node() { cout << "Node 가 삭제되었습니다" << endl; }
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
	~AdjacencyList()
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			Node* delNode = list[i];
			Node* nextNode = list[i];
			if (delNode == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = delNode->next;
					delete delNode;
					delNode = nextNode;
				}
			}
		}
	}
	template<typename T>
	friend ostream& operator << (ostream& ost, AdjacencyList<T>& adj);
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

	cout << list << endl;
	return 0;
}

template<typename T>
ostream& operator<<(ostream& ost, AdjacencyList<T>& adj)
{
	for (int i = 0; i < adj.size; i++)
	{
		ost << adj.vertex[i] << ": ";
		typename AdjacencyList<T>::Node* current = adj.list[i];
		while (current != nullptr)
		{
			ost << current->data << " ";
			current = current->next;
		}
		ost << endl;
	}

	return ost;
}

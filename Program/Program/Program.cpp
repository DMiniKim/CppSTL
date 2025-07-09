#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	int size;
	struct Node
	{
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;
	};
	Node* head;
	Node* tail;

public:
	List()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

};



int main()
{
	List<int> list;

	return 0;
}
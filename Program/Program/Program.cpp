#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	int size;
	struct Node
	{
		T data = NULL;
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
	~List()
	{

		while (head != nullptr)
		{
			pop_back();
		}
		if (head == nullptr)
		{
			cout << "다 지워졌습니다 " << endl;
		}
	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			tail = newNode;
			head = newNode;
		}
		else
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "데이터가 비어있습니다" << endl;
		}
		else
		{
			Node* delNode = head;
			if (size == 1)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				head = delNode->next;
				head->prev = nullptr;
			}
			delete delNode;
			size--;
		}
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		size++;
	}
	void pop_back()
	{
		if (tail == nullptr)
		{
			cout << "데이터가 이나인데스" << endl;
		}
		else
		{
			Node* delNode = tail;
			if (size == 1)
			{
				head = tail = nullptr;
			}
			else
			{
				tail = delNode->prev;
				tail->next = nullptr;
			}
			delete delNode;
			size--;
		}
	}
	bool empty()
	{
		return size == 0;
	}
};



int main()
{
	List<int> list;

	list.push_front(10);
	list.push_back(20);
	
	//list.pop_front();
	//list.pop_back();
	//list.pop_back();
	cout << list.empty() << endl;
	cout << "==========스택의 영역은 여기까지입니다==========" << endl;
	return 0;
}
#include <iostream>

using namespace std;

template <typename T>

class CircleList
{
private:
	int size;
	struct Node
	{
		T data;
		Node* next;
		Node()
		{
			data = NULL;
			next = nullptr;
		}
	};
	Node* head;
public:
	CircleList()
	{
		size = 0;
		head = nullptr;
	}
	~CircleList()
	{
		while (head != nullptr)
		{
			pop_back();
		}
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
		size++;
	}
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "이미 비어있는 상태입니다." << endl;
		}
		else
		{
			Node* delNode = head;
			if (size == 1)
			{
				head = nullptr;
			}
			else
			{
				Node* temp = head->next;
				while (temp->next != head)
				{
					temp = temp->next;
				}
				head = temp;
				head->next = delNode->next;
			}
			delete delNode;
			size--;
		}
	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		size++;
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "이미 비어있습니다" << endl;
		}
		else
		{
			Node* delNode = head->next;
			if (size == 1)
			{
				head = nullptr;
			}
			else
			{
				head->next = delNode->next;
			}
			delete delNode;
			size--;
		}
	}
	void empty()
	{
		return size == 0;
	}
	void remove(T data)
	{
		Node* prevNode = head;
		Node* delNode = head->next;
		while (delNode != head)
		{
			if (delNode->data == data)
			{
				prevNode->next = delNode->next;
				delete delNode;
				delNode = prevNode->next;
				size--;
			}
			else
			{
				prevNode = delNode;
				delNode = delNode->next;
			}
		}
	}
};


int main()
{
	CircleList<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(40);
	list.push_back(80);
	list.push_front(5);
	return 0;
}
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
	//void remove(T data)
	//{
	//	if (head == nullptr)
	//	{
	//		cout << "저장된 Data 가 없습니다." << endl;
	//	}
	//	else
	//	{
	//		// 경우의 수 
	//		// 4개 이상 -> 3개로 줄어 들거임
	//		Node* delNode = head;
	//		while (delNode != nullptr)
	//		{
	//			// 1개 있을 때
	//			if (size == 1)
	//			{
	//				pop_front();
	//			}
	//			// 2개 있을 때
	//			else if (size == 2)
	//			{
	//
	//				if (head->data == data)
	//				{
	//					pop_front();
	//				}
	//				if (tail->data == data)
	//				{
	//					pop_back();
	//				}
	//
	//			}
	//			// 3개 있을 때
	//			else if (size == 3)
	//			{
	//				if (head->data == data)
	//				{
	//					pop_front();
	//				}
	//				else if (tail->data == data)
	//				{
	//					pop_back();
	//				}
	//				else if
	//				{
	//					delNode = delNode->next;
	//					if (delNode.data == data)
	//					{
	//						head.next = tail;
	//						tail.prev = head;
	//						delete delNode;
	//						size--;
	//					}
	//				}
	//			}
	//			else if (size > 3)
	//			{
	//				while (delNode->data != data)
	//				{
	//					delNode = delNode->next;
	//				}
	//				delNode->prev->next = delNode->next;
	//				delNode->next->prev = delNode->prev;
	//				delete delNode;
	//				size--;
	//			}
	//		}
	//	}
	//}
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
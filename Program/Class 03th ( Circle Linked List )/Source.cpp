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
		int deleteCount = 0;
		while (delNode != head)
		{
			if (delNode->data == data)
			{
				prevNode->next = delNode->next;
				delete delNode;
				delNode = prevNode->next;
				size--;
				deleteCount++;
			}
			else
			{
				prevNode = delNode;
				delNode = delNode->next;
			}
		}
		// 여기부턴 delnode가 head랑 같은 상태 
		// 위 while문에서 할거 다 하고 head에 도착했을 떄 진행코드
		// 그래서 마지막 노드의 data가 같거나 아닌경우만 설정
		if (delNode->data == data)
		{
			head = nullptr;
			delete delNode;
			size--;
		}
		// 삭제한 노드 카운트세서 0일 시 아래와 같이 출력
		if (deleteCount == 0)
		{
			cout << "삭제하려는 data는 저장되어 있지 않은 상태입니다." << endl;
		}
	}
	void showData()
	{
		Node* temp = head->next;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << "번째 data는 " << temp->data << "입니다" << endl;
			temp = temp->next;
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
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_front(1);
	list.push_front(1);
	list.showData();
	cout << "===========================" << endl;
	list.remove(1);
	list.showData();

	return 0;
}
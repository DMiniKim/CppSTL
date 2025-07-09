#include <iostream>

using namespace std;



template <typename T>
class List
{
private:
	int size;
	struct Node
	{
		Node* next;
		T data;
		~Node()
		{
			cout << "삭제되었습니다" << endl;
		}
	};
	Node* head;
public:
	List()
	{
		size = 0;
		head = nullptr;
	}
	~List()
	{
		while (head != nullptr)
		{
			Node* delNode = head;
			head = delNode->next;
			delete delNode;
			//pop_front(); <- 딸깍
		}
	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if ((head == nullptr) && size == 0)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	void pop_front()
	{
		Node* deleteNode = head;
		if (deleteNode == nullptr&& size == 0)
			cout << "비어있습니다" << endl;
		else
		{
			head = deleteNode->next;
			delete deleteNode;
			size--;
		}

	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (head == nullptr&&size == 0)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			Node* tailNode = head;
			while (tailNode->next != nullptr)
			{
				tailNode = tailNode->next;
			}
			tailNode->next = newNode;
		}
		size++;
	}
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
		}
		else
		{
			Node* delNode = head;
			Node* prevNode = head;
			while (delNode->next != nullptr)
			{
				prevNode = delNode;
				delNode = delNode->next;
			}
			if (size == 1)
			{
				head = nullptr;
			}
			prevNode->next = nullptr;
			delete delNode;
			size--;
		}
	}
	bool empty()
	{
		return (head == nullptr);
	}
};


int main()
{
	List<int> list;
	list.push_front(10);
	list.push_front(20);


	return 0;
}
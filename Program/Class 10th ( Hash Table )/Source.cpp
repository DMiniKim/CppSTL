#include <iostream>
#include <time.h>
#include <random>

#define SIZE 6
using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
		Node()
		{
			key = NULL;
			value = NULL;
			next = nullptr;
		}
	};
	struct Bucket
	{
		int count;
		Node* head;
		Bucket()
		{
			count = 0;
			head = nullptr;
		}
	};
	Bucket bucket[SIZE];
public:
	template <typename T>
	const unsigned int& hash_function(T key)
	{
		// 양수만 저장 할 수 있는 자료형 = key->  0 ~ 5
		unsigned int hashKey = (unsigned int)key % SIZE;

		return hashKey;
	}
	Node* create_node(KEY key, VALUE value)
	{
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		return newNode;
	}
	void insert(KEY key, VALUE value)
	{
		unsigned int tempHashkey = hash_function(key);
		Node* newNode = create_node(key, value);
		if (bucket[tempHashkey].count == 0)
		{
			bucket[tempHashkey].head = newNode;
		}
		else
		{
			newNode->next = bucket[tempHashkey].head;
			bucket[tempHashkey].head = newNode;
		}
		bucket[tempHashkey].count++;
		// 로그
		cout << "Log :" << bucket[tempHashkey].head->key << "\t" << bucket[tempHashkey].head->value << endl;
	}
	void erase(KEY key)
	{
		unsigned int hashindex = hash_function(key);
		Node* delNode = bucket[hashindex].head;
		Node* prevNode = nullptr;

		//while (prevNode->next != nullptr)
		//{
		//	if (bucket[hashindex].count <= 0)
		//	{
		//		cout << "없습니다 꺼지쇼" << endl;
		//		return;
		//	}
		//	else
		//	{
		//		if (delNode->key == key)		// key가 같다면
		//		{
		//			if (bucket[hashindex].count == 1)		//하나 일 경우
		//			{
		//				bucket[hashindex].head = nullptr;
		//				delete delNode;
		//				bucket[hashindex].count--;
		//				cout << "삭제 완료" << endl;
		//
		//			}
		//			else if (bucket[hashindex].count > 1)	// 두 개 이상 일 떄
		//			{
		//				if (delNode == bucket[hashindex].head)	// 삭제노드가 버켓헤드랑 겹친다면 
		//				{
		//					bucket[hashindex].head = delNode->next;
		//				}
		//				prevNode->next = delNode->next;
		//				delete delNode;
		//				delNode = prevNode->next;
		//				bucket[hashindex].count--;
		//				cout << "삭제 완료" << endl;
		//			}
		//		}
		//		else							// key 가 다르다면 스킵
		//		{
		//			prevNode = delNode;
		//			delNode = delNode->next;
		//		}
		//	}
		//}
		if (delNode == nullptr)
		{
			cout << "not key Found" << endl;
			return;
		}
		else
		{
			while (delnode != nullptr)
			{
				if (delNode->key == key)
				{
					if (delNode == bucket[hashindex].head)
					{
						bucket[hashindex].head = delNode->next;
					}
					else
					{
						prevNode->next = delNode->next;
						delete delNode;
						delNode = prevNode->next;
						bucket[hashindex].count--;
					}
				}
			}
		}

	}
	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* nextNode = bucket[i].head;
			Node* delNode = bucket[i].head;
			while (delNode != nullptr)
			{
				nextNode = delNode->next;
				delete delNode;
				delNode = nextNode;
			}
			if (bucket[i].head != nullptr)	bucket[i].head = nullptr;
		}
	}
};

int main()
{
	HashTable<const char*, int> ht;
	ht.insert("KDKDKDKDSKDK", 24123525);
	ht.insert("208730tjss", 16542589);
	ht.insert("s;fjlgksjkwj", 22222222);
	ht.insert("K", 25);

	ht.erase("K");

	return 0;
}
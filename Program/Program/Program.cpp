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
	void erase()
	{

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
	ht.insert("KDKDKDKDSKDK",24123525);
	ht.insert("208730tjss", 16542589);
	ht.insert("s;fjlgksjkwj", 22222222);
	ht.insert("K", 25);

	return 0;
}
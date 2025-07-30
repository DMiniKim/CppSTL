#include<iostream>

using namespace std;
template <typename T>
class Set
{
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		Node(T _data, Node* left = nullptr, Node* right = nullptr) { data = _data; }
		~Node() { cout << "Node is Delete" << endl; }
	};
	Node* root;
	int nodeCount;
public:
	Set() : root(nullptr), nodeCount(0) {};
	void insert(T data)
	{
		root = insertSupport(data, root);
	}
	Node* insertSupport(T data, Node* currentRoot)
	{
		Node* currentNode = currentRoot;
		if (currentNode == nullptr)
		{
			nodeCount++;
			return new Node(data);
		}
		else if (currentNode->data < data)
		{
			currentNode->right = insertSupport(data, currentNode->right);
		}
		else if (currentNode->data > data)
		{
			currentNode->left = insertSupport(data, currentNode->left);
		}
		else
		{
			cout << "뭔가 잘못 된 상태입니다 " << endl;
		}
		return currentNode;
	}
	void release(Node* root)
	{
		if (root == nullptr) return;
		release(root->left);
		release(root->right);
		delete root;

	}
	~Set()
	{
		Node* delNode = root;
	}

};


int main()
{
	return 0;
}
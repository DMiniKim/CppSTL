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
		// 나 ver
		//if (root == nullptr) return;
		//release(root->left);
		//release(root->right);
		//delete root;
		// 강사님 ver
		if (root != nullptr)
		{
			release(root->left);
			release(root->right);
			delete root;
		}
	}
	void erase(T data)
	{
		//Node* currentNode = root;
		//Node* prevNode = root;
		//while (currentNode != nullptr)
		//{
		//	if (data > currentNode->data)			// 입력 데이터가 현재노드 데이터보다 클 때 우측이동
		//	{
		//		prevNode = currentNode;
		//		currentNode = currentNode->right;
		//	}
		//	else if (data < currentNode->data)		// 입력 데이터가 현재노드 데이터보다 작을 때 좌측이동
		//	{
		//		prevNode = currentNode;
		//		currentNode = currentNode->left;
		//	}
		//	else if (data == currentNode->data)		// 같을 때
		//	{
		//		if (root->data == currentNode->data)	// 찾은 놈이 root 일 때
		//		{
		//			root = currentNode->right;
		//			if (currentNode->right == nullptr) root = currentNode->left;
		//
		//			delete currentNode;
		//			return;
		//		}
		//		else if (currentNode->left == nullptr && currentNode->right == nullptr)	// 자식 없음
		//		{
		//
		//		}
		//		else if (currentNode->left == nullptr || currentNode->right == nullptr)	// 자식 하나
		//		{
		//
		//		}
		//		else 
		//		{
		//
		//		}
		//	}
		//	else if (currentNode == nullptr)
		//	{
		//		cout << "data is Not Found" << endl;
		//		return;
		//	}
		//}

		// 강사님
		Node* currentNode = root;
		Node* parentNode = nullptr;
		while (currentNode != nullptr && currentNode->data != data)
		{
			parentNode = currentNode;

			if (currentNode->data > data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}
		if (currentNode == nullptr)
		{
			cout << "The data does not exist" << endl;
		}
		if (currentNode->left == nullptr && currentNode->right == nullptr)			// 자식 0
		{
			if (currentNode->data == root)
			{
				root = nullptr;
			}
			else
			{
				if (parentNode != nullptr)
				{
					if (parentNode->left == currentNode)
					{
						parentNode->left = nullptr;
					}
					else if (parentNode->right == currentNode)
					{
						parentNode->right = nullptr;
					}
				}
			}
			delete currentNode;
		}
		else if (currentNode->left != nullptr && currentNode->right != nullptr)		// 자식 2
		{
			//if (parentNode->left == currentNode)
			//{
			//	Node* traceNode = currentNode->right;
			//
			//	while (traceNode->left != nullptr)
			//	{
			//		traceNode = traceNode->left;
			//	}
			//	traceNode->left = currentNode->left;
			//
			//	Node* rightChildNode = traceNode;
			//
			//	while (rightChildNode->right != nullptr)
			//	{
			//		rightChildNode = rightChildNode->right;
			//	}
			//	rightChildNode->right = currentNode->right;
			//}
			Node* childNode = currentNode->right;
			Node* traceNode = currentNode;
			while (childNode->left != nullptr)
			{
				traceNode = childNode;
				childNode = childNode->left;
			}
			currentNode->data = childNode->data;
			traceNode->left = childNode->right;
			delete childNode;
		}
		else 																		// 자식 1
		{
			if (currentNode == root)
			{
				if (currentNode->left != nullptr)
				{
					root = currentNode->left;
				}
				else
				{
					root = currentNode->right;
				}
			}
			else
			{
				if (parentNode->left == currentNode)
				{
					if (currentNode->left == nullptr)
					{
						parentNode->left = currentNode->right;
					}
					else
					{
						parentNode->left = currentNode->left;
					}
					delete currentNode;
				}
				else
				{
					if (currentNode->left == nullptr)
					{
						parentNode->right = currentNode->right;
					}
					else
					{
						parentNode->right = currentNode->left;
					}
					delete currentNode;
				}
			}
		}
	}
	void inorder()
	{
		inorder(root);
	}
	void inorder(Node* root)
	{
		if (root != nullptr)
		{
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
		cout << root << endl;
	}
	~Set()
	{
		release(root);
	}

};


int main()
{
	Set<int> set;
	return 0;
}
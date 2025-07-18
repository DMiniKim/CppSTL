#include <iostream>

using namespace std;

class String
{
private:
	int size;
	char* pointer;
public:
	String()
	{
		size = 0;
		pointer = nullptr;
	}
	void operator = (const char* c)
	{
		size = strlen(c) + 1;
		if (pointer == nullptr)
		{
			pointer = new char[size];
			for (int i = 0; i < size; i++)
			{
				pointer[i] = c[i];
			}
		}
		else if (pointer != nullptr)
		{
			char* temp = new char[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = c[i];
			}
			delete[] pointer;
			pointer = temp;
		}

	}
	const int& Length()
	{
		return size;
	}
	const char& operator[](const int& index)
	{
		return pointer[index];
	}
	void Find(const char* c)
	{

	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << pointer[i];
		}
		cout << endl;
	}
	~String()
	{
		if (pointer != nullptr)
		{
			delete[] pointer;	
		}
	}
};


int main()
{
	String str;
	str = "League Of Legend";
	str.Print();
	str = "Lost Ark";
	str.Print();
	cout << "====================================" << endl;
	for (int i = 0; i < str.Length(); i++)
	{
		cout << str[i];
	}
	return 0;
}
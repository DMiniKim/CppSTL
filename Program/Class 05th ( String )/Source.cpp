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
		return size - 1;
	}
	const char& operator[](const int& index)
	{
		return pointer[index];
	}
	void append(const char* word)
	{
		int resize = size + strlen(word) + 1;
		char* temp = new char[resize];
		for (int i = 0; i < resize - 1; i++)
		{
			if (i <= Length())
			{
				temp[i] = pointer[i];
			}
			else
			{
				temp[i] = word[i - size];
			}
		}
		size = resize;
		delete[] pointer;
		pointer = temp;
	}
	unsigned long long Find(const char* word)
	{
		int len = Length() - strlen(word);
		int i = 0;
		int j = 0;
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < strlen(word);j++)
			{
				if (pointer[i + j] != word[j])
				{
					break;
				}
			}
			if (j == strlen(word))
			{
				return i;
			}
		}

		return 18446744073709551615;
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
	str = "League";
	for (int i = 0; i < str.Length(); i++)
	{
		cout << str[i];
	}
	cout << endl;

	cout << "====================================" << endl;
	str.append(" of Legends");
	for (int i = 0; i < str.Length(); i++)
	{
		cout << str[i];
	}
	cout << endl;

	cout << str.Find("ejd") << endl;




	return 0;
}
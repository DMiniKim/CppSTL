#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	int dataSize;				// data가 저장된 벡터 크기
	int capacity;			    // 최대 용량

public:
	T* container;				// 자료들 시작 주소 담는 포인터
	Vector()
	{
		dataSize = 0;
		capacity = 0;
		container = nullptr;
	}
	~Vector()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
	void resize(int newSize)
	{
		// 1. capacity에 새로운 size값을 저장.
		// 2. 새로운 포인터 변수를 생성, 새롭게 만들어진
		//	  메모리 공간을 가리키도록 한다.
		// 3. 새로운 메모리 공간의 값을 초기화한다.
		// 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어줌.
		// 5. 기존 배열의 메모리를 해제한다.
		// 6. 기존 배열을 가리키던 포인터 변수의 주소를 새로운 배열의
		//	  시작 주소로 변경한다.

		capacity = newSize;

		T* temp = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temp[i] = NULL;
		}
		for (int i = 0; i < dataSize; i++)
		{
			temp[i] = container[i];
		}
		if (container != nullptr)
		{
			delete[] container;
		}
		container = temp;
	}
	void push_back(T data)
	{
		if (container == nullptr)
		{
			resize(1);
			container[capacity] = data;

			dataSize++;
		}
		else
		{
			if (capacity == dataSize)
			{
				resize(capacity * 2);
				push_back(data);
			}
			else
			{
				int index = 0;
				while (container[index] != NULL)
				{
					index++;
				}
				container[index] = data;
			}
		}
	}
};

int main()
{
	Vector<int> vector;
	vector.push_back(10);
	
	return 0;
}
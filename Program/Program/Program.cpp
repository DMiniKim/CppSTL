#include <iostream>
using namespace std;

template <typename T>

// 그래프
// 방향 그래프		-> 특정한 방향으로 연결된 그래프
// 무방향 그래프	-> 양방향으로 연결된 그래프
// 가중치 그래프	-> 간선에 가중치가 있는 그래프	

class ADjacencyMatrix
{
private:
	T* vertex;				// 정점의 집합체
	int capacity;			// 그래프의 크기
	int size;		        // 정점의 개수	

	int matrixCount;		// 인접 행렬의 개수
	int** matrix;
public:
	ADjacencyMatrix()
	{
		size = 0;
		capacity = 0
			matrixCount = 0;
		vertex = nullptr;
		matrix = nullptr;
	}
	void push(T data)
	{
		if (size >= capacity)
		{
			resize(capacity * 2);
		}
		if (vertex == nullptr)
		{
			resize(1);
			vertex = new T(data);

		}
		else
		{
			vertex[size] = data;
		}
		size++;
	}
	void resize(int newSize)
	{
		capacity = newSize;

		T* temp = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temp[i] = NULL;
		}
		for (int i = 0; i < size; i++)
		{
			temp[i] = vertex[i];
		}
		if (vertex != nullptr)
		{
			delete[] vertex;
		}
		vertex = temp;
	}
	void resize()
	{
		// 인접행렬의 메모리를 새로 생성하는 함수
		int** newMatrix = new int* [size];
		for (int i = 0; i < size; i++)
		{
			newMatrix[i] = new int[size](0);
		}
		for (int i = 0; i < matrixCount; i++)
		{
			for (int j = 0; j < matrixCount; j++)
			{
				newMatrix[i][j] = matrix[i][j];
			}
		}
		if (matrix != nullptr)
		{
			for (int i = 0; i < matrixCount; i++)
			{
				delete[] matrix[i]
			}
			delete[] matrix;
		}
		matrix = newMatrix;
		matrixCount = size;
	}
	void edge(int i, int j)
	{
		// 1. vertex가 없는 상태에서 연결하면 
		//    인접 행렬이 없다고 나와야 함.
		if (vertex == nullptr)
		{
			cout << "Not Found Matrix" << endl;
		}
		// 2. vertex의 크기 범위를 벗어나게되면 
		//    연결이 되지 않도록 설정해야 함.
		else if (i >= size || j >= size)
		{
			cout << "Out Of range" << endl;
		}
		// 3. 인접 행렬이 없을 때 정점의 크기만큼 
		//    인접행렬을 생성함.
		else
		{
			if (matrix == nullptr)
			{
				matrixCount = size;
				matrix = new int* [size];
				for (int i = 0; i < size; i++)
				{
					matrix[i] = new int[size](0);
				}
				matrix[j][i] = 1;
				matrix[i][j] = 1;
			}
			else if (matrixCount < size)
			{
				resize();
				matrix[j][i] = 1;
				matrix[i][j] = 1;
			}
			else
			{
				matrix[j][i] = 1;
				matrix[i][j] = 1;
			}
		}
	}
	std::ostream& operator<<(std::ostream& o, const ADjacencyMatrix<T>& matrix)
	{
		for (int i = 0; i < size; i++)
		{
			for (int  j = 0; j < size; j++)
			{
				o << matrix[i][j] << " ";
			}
			o << endl;
		}
		return o;
	} /// 안되넹 쳇
};



int main()
{
	ADjacencyMatrix<int> matrix;
	matrix.push(5);
	matrix.push(7);
	matrix.push(12);
	cout << matrix << endl;

	return 0;

}
#include <iostream>

// Basic Template 
template <typename T>
class Vector
{
public:
	void clear();  // ע������ֻ������
private:
	T* elements;
};

template <typename T>
void Vector<T>::clear()  // ������ʵ�ַ�������
{
	// Function body
}

//Template Function
template <typename T>
T add(T a, T b)
{
	return a + b;
}

int main()
{

	Vector<int> VectorInt{};

	int a = 2;
	char b = 3;
	int c = add(a, b);

	getchar();
}
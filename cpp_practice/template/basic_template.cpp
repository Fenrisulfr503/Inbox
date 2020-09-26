#include <iostream>

// Basic Template 
template <typename T>
class Vector
{
public:
	void clear();  // 注意这里只有声明
private:
	T* elements;
};

template <typename T>
void Vector<T>::clear()  // 函数的实现放在这里
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
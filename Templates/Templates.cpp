#include <iostream>

using namespace std;

template<typename T = double, int size = 3>
class Stack
{
	T _elements[size];
	int _pointer;
public:
	Stack()
	{
		_pointer = size - 1;
		T element;
		for (int i = 0; i < size; i++)
		{
			cout << "Pass element no. " << i + 1 << ": ";
			cin >> element;
			_elements[i] = element;
		}
	}
	void DecrementPointer()
	{
		if (_pointer > 0)
			_pointer--;
	}
	void IncrementPointer()
	{
		if (_pointer < size - 1)
		_pointer++;
	}
	void ResetPointer()
	{
		_pointer = size - 1;
	}
	T Peek()
	{
		return _elements[_pointer];
	}
	int Size()
	{
		return size;
	}
};


template<typename T = double, int size = 3>
T sum(Stack<T, size> stack)
{
	T sum = 0;
	for (int i = 0; i < stack.Size(); i++)
	{
		sum += stack.Peek();
		stack.DecrementPointer();
	}
	stack.ResetPointer();
	return sum;
}


int main()
{
	cout << "Doubles stack" << endl;
	Stack<> stackD3;
	double sumD3 = sum<>(stackD3);
	cout << "Floats stack" << endl;
	Stack<float, 4> stackF4;
	float sumF4 = sum<float, 4>(stackF4);
	cout << "Ints stack" << endl;
	Stack<int, 5> stackI5;
	int sumI5 = sum<int, 5>(stackI5);

	cout << endl;
	cout << "Sum of doubles stack: " << sumD3 << endl;
	cout << "Sum of floats stack: " << sumF4 << endl;
	cout << "Sum of ints stack: " << sumI5 << endl;

	system("pause");
	return 0;
}
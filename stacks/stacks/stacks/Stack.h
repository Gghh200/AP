#include "Values.cpp"

template <typename T> 
class Stack
{
	private:
		int max;
		int current;
		Values<T>** values;
	public:
		Stack(int max);
		Stack(Values<T>**& values);
		~Stack();
		void push(T value);
		T pop();
		T peek();
		void clear();
		bool isFull();
		bool isEmpty();
		void changeSize(int size);
		int getCurrent();
};


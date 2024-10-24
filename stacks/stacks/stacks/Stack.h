template <typename T> 
class Stack
{
	private:
		int max;
		int current;
		T* values;
	public:
		Stack(int max);
		Stack(T*& values);
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


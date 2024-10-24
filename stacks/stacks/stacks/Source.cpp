#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
	Stack<int>* ints = new Stack<int>(3);
	ints->push(1);
	cout << ints->pop();
	ints->~Stack();
	#ifdef _DEBUG
		_onexit(_CrtDumpMemoryLeaks);
	#endif
	return 0;
}
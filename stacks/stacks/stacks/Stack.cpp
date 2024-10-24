#include "Stack.h"
#include <iostream>

int main(){
	std::cout << "test";
	Stack<int>* ints = new Stack<int>(3);
	ints->push(1);
	std::cout << ints->pop();
	ints->~Stack();
}
template <typename T>
Stack<T>::Stack(int max) {
	T** values = (T**)malloc(sizeof(T*) * max);
	this->max = max;
}

template <typename T>
Stack<T>::Stack(T*& value){
	T* values = values;
}

template <typename T>
Stack<T>::~Stack() {
	free(values);
	values = nullptr;
}

template <typename T>
void Stack<T>::push(T value) {
	if (current == max) {
		realloc(values, sizeof(T*) * (max + 1));
		max += 1;
	}
	values[current] = value;
}

template <typename T>
T Stack<T>::pop() {
	if (current == -1) {
		return NULL;
	}
	else {
		int temp = current;
		current - 1;
		return values[current];
	}
}

template <typename T>
T Stack<T>::peek() {
	if (current == -1) {
		return NULL;
	}
	else {
		return values[current];
	}
}

template <typename T>
void Stack<T>::clear() {
	free(values);
	values = nullptr;
	T ** values = (T**)malloc(sizeof(T*) * max);
}

template <typename T>
bool Stack<T>::isFull() {
	if (current == max) {
		return true;
	}
	return false;
}

template <typename T>
bool Stack<T>::isEmpty() {
	if (current == -1) {
		return true;
	}
	return false;
}

template <typename T>
void Stack<T>::changeSize(int size) {
	realloc(values, sizeof(T*) * (max + size));
	max += size;
}

template <typename T>
int Stack<T>::getCurrent() {
	return current;
}
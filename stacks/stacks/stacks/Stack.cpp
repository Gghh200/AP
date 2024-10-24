#include "Stack.h"
#include <iostream>

template <typename T>
Stack<T>::Stack(int max) {
	Values<T>** values = (Values<T>**)malloc(sizeof(Values<T>*) * max);
}

template <typename T>
Stack<T>::Stack(Values<T>**& value){
	Values<T>** values = values;
}

template <typename T>
Stack<T>::~Stack() {
	for (int i = 0; i < max - 1; i++) {
		free(values[i]);
		values[i] = nullptr;
	}
	free(values);
	values = nullptr;
}

template <typename T>
void Stack<T>::push(T value) {
	if (current == max) {
		realloc(values, sizeof(Values<T>*) * (max + 1));
		max += 1;
	}
	values[current]->type = value;
}

template <typename T>
T Stack<T>::pop() {
	if (current == -1) {
		return NULL;
	}
	else {
		int temp = current;
		current - 1;
		return values[current]->type;
	}
}

template <typename T>
T Stack<T>::peek() {
	if (current == -1) {
		return NULL;
	}
	else {
		return values[current]->type;
	}
}

template <typename T>
void Stack<T>::clear() {
	free(values);
	values = nullptr;
	Values<T> ** values = (Values<T>**)malloc(sizeof(Values<T>*) * max);
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
	realloc(values, sizeof(Values<T>*) * (max + size));
	max += size;
}

template <typename T>
int Stack<T>::getCurrent() {
	return current;
}
#include <iostream>
#include "question.h"

using namespace std;

question::question(){
	srand(time(NULL));
	value1 = rand() % 21;
	value2 = rand() % 21;
	UserAnswer = 999999999;
}
int* question::getValues() {
	int* values = new int[2] {value1, value2};
	return values;
}

void question::userAnswer() {
	cout << "What is " << value1 << getSymobl() << value2 << " = ";
}

void question::SetUserAnswer(int UserAnswer){
	this->UserAnswer = UserAnswer;
}
int question::getUser(){
	return UserAnswer;
}
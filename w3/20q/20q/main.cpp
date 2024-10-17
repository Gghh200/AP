#include <iostream>
#include "subtraction.h"
#include "addition.h"

using namespace std;

int main() {
	srand(time(NULL));
	question** questions = new question*[20];
	for (int i = 0; i < 20; i++) {
		int option = rand() % 2;
		if(option == 0){
			questions[i] = new addition();
		}
		else {
			questions[i] = new subtraction();
		}
		questions[i]->userAnswer();
		int answer;
		cin >> answer;
		questions[i]->SetUserAnswer(answer);
	}
	cout << "Correct Answers" << "\n" << "===============";
	for (int i = 0; i < 20; i++){
		if(questions[i]->getValues()[0] + questions[i]->getValues()[1] == questions[i]->getUser()){
			questions[i]->userAnswer();
			cout << questions[i]->getValues()[0] + questions[i]->getValues()[1];
		}
	}
	cout << "Wrong Answers" << "\n" << "===============";
	for (int i = 0; i < 20; i++){
		if(questions[i]->getValues()[0] + questions[i]->getValues()[1] != questions[i]->getUser()){
			questions[i]->userAnswer();
			cout << questions[i]->getValues()[0] + questions[i]->getValues()[1] << " you answered " << questions[i]->getUser();
		}
	}
	return 0;
}

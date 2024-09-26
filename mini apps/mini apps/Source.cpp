#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	srand(time(0));
	void menu();
	menu();
	return 0;
}

void menu() {
	void counting();
	void square();
	int input;
	cout << "P4CS Mini Applications \n ----------------------";
	cout << "Please select an option: \n 1) Keep Counting \n 2) Square Root Calculator \n 3) Encrypt Text (Caesar Cipher) \n 4) Decrypt Text (Caesar Cipher) \n 5) Quit";
	cout << "\n Pealse enter 1,2,3,4,5: ";
	cin >> input;
	switch (input) {
	case 1:
		counting();
		break;
	case 2:
		square();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
}

void counting() {
	int count = 0;
	int answer;
	cout << "ADDING GAME \n ----------------------";
	for (int i = 0; i < 10; i++) {
		int number1 = rand() % 11;
		int number2 = rand() % 11;
		cout << "What is " << number1 << " + " << number2 << " = ";
		cin >> answer;
		if (answer == number1 + number2) {
			count ++;
		}
	}
	cout << "You got " << count << " out of 10";
}
void square() {
	int InputNumber;
	int InputPlaces;
	cout << "SQUARE ROOT CALCULATOR \n ----------------------";
	cout << "\n Enter number: ";
	cin >> InputNumber;
	cout << "\n Enter number of decimal places: ";
	cin >> InputPlaces;

}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
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
	void encrypt();
	int input;
	cout << "P4CS Mini Applications \n ----------------------";
	cout << "Please select an option: \n 1) Keep Counting \n 2) Square Root Calculator \n 3) Encrypt Text (Caesar Cipher) \n 4) Decrypt Text (Caesar Cipher) \n 5) Quit";
	cout << "\n Please enter 1,2,3,4,5: ";
	cin >> input;
	switch (input) {
	case 1:
		counting();
		break;
	case 2:
		square();
		break;
	case 3:
		encrypt();
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
	float lower = 0;
	cout << "SQUARE ROOT CALCULATOR \n ----------------------";
	cout << "\n Enter number: ";
	cin >> InputNumber;
	cout << "\n Enter number of decimal places: ";
	cin >> InputPlaces;
	float upper = InputNumber;
	while(lower + pow(10, InputPlaces * -1) <= upper){
		float avg = (upper + lower) / 2;
		float test = pow(avg, 2);
		if(test > InputNumber){
			upper = avg;
		}else{
			lower = avg;
		}
	}
	cout << setprecision(InputPlaces + 1) << (upper + lower) / 2 << "\n";
}
void encrypt(){
	string plain;
	int shift;
	char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	cout << "Encrypt \n ----------------------";
	cout << "\n Enter string: ";
	cin >> plain;
	cout << "\n Enter shift: ";
	cin >> shift;
	for(int i = 0; i < plain.length() - 1; i++){
		int place = find(characters[0],characters[36], plain[i]);
		if(place + shift > 36){
			place = place - shift;
		}else{
			place = place + shift;
		}
		plain[i] = characters[place];
	}
	cout << plain;
}
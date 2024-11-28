#include <algorithm>
#include"House.h"

void menu(House& house);

int main(){
	House house = House(25, 15);

	ifstream File;
	File.open("house.txt",ios::in);
	Device Temp;
	string number;
	File.getline ((char*)number.c_str(), sizeof(number));
	for(int i = 0; i < stoi(number); i++){
		
	}
	File.close();

	menu(house);
	
	ofstream file;
    file.open("house.txt", ofstream::out | ofstream::trunc);
    file.close();

	file.open("house.txt", ios::app);
	file << to_string(house.GetSize());
	file << endl;

	#ifdef _DEBUG
		_onexit(_CrtDumpMemoryLeaks);
	#endif
	return 0;
}

void menu(House& house){
	bool exit = true;
	house.display();
	string UserInput;
while (exit){
	cout << "[device name]: Perform that device’s one-click action \n" 
		<< "1: List devices \n"
		<< "2: Sort by name \n"
		<< "3: Sort by device type (by name as secondary order) \n"
		<< "4: Select device to interact with it’s full feature set \n"
		<< "5: Add device \n"
		<< "6: Exit \n";
		cin >> UserInput;
		switch(UserInput[0]) {
			case '1':{
				house.display();
				exit = house.continues();
				break;
			}
			case '2':{
				house.NameSort();
				house.display();
				exit = house.continues();
				break;
			}
			
			case '3':{
				house.TypeSort();
				house.display();
				exit = house.continues();
				break;
			}
			case '4':{
				cout << "Enter device name : \n";
				string name;
				cin >> name;
				Device* current = house.find(name);
				if(current != nullptr){
					current->DisplayFunctions();
				}
				exit = house.continues();
				break;
			}
			case '5':{
				house.Add();
				exit = house.continues();
				break;
			}
			case '6':{
				house.ChangeEnd();
				exit = false;
				break;
			}
			default:{
				Device* current = house.find(UserInput);
				if(current != nullptr){
					cout << "Couldn't find device \n";
				}
				if(OneClick* test = dynamic_cast<OneClick*>(current); test == nullptr){
					cout << "That device has no oneclick action \n";
				}else{
					OneClick* temp = dynamic_cast<OneClick*>(current);
					temp->ChangeOnOff();
				}
				exit = house.continues();
				break;
			}
		}
	}
}

#include <list>
#include <algorithm>
#include <fstream>
#include "Light.h"
#include "Plug.h"
#include "Radiator.h"
#include "Speaker.h"
#include "TempHum.h"
#include "Thermostat.h"
#include "DeviceFact.h"

void ChangeTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin);
void UpdateTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin);
void menu(bool end, list<Device*>& House, int& temp, DeviceFact& Factory);
Device* Add(bool& end, int& temp, DeviceFact& Factory);
bool continues();

int main(){
	bool end = true;
	int temp = 5;
	int TempMax = 30;
	int TempMin = 5;
	list<Device*> House;
	DeviceFact Factory = DeviceFact();
	ifstream File;
	File.open("house.txt",ios::in);
	Device Temp;
	string number;
	File.getline ((char*)number.c_str(), sizeof(number));
	for(int i = 0; i < stoi(number); i++){
		File.getline((char*)&(Temp), sizeof(Temp));
		string type = Temp.GetType();
		if(type == "Light"){
			House.push_front(new Light());
		}else if(type == "Plug"){
			House.push_front(new Plug(end));
		}else if(type == "Radiator"){
			House.push_front(new Radiator(temp, end));
		}else if(type == "Speaker"){
			House.push_front(new Speaker());
		}else if(type == "TempHum"){
			House.push_front(new TempHum(end, temp));
		}else if(type == "Thermostat"){
			House.push_front(new Thermostat(end));
		}
		File.getline((char*)&(*House.front()), sizeof(*House.front()));
	}
	File.close();

	cout << "";
	ChangeTemp(end, House, temp, TempMax, TempMin);
	menu(end, House, temp , Factory);

	ofstream file;
    file.open("house.txt", ofstream::out | ofstream::trunc);
    file.close();

	file.open("house.txt", ios::app);
	file << to_string(House.size());
	file << endl;
	for(Device* device : House){
		file.write((char*)&*device,sizeof(*device));
   		file << endl;
		file.write((char*)&*device,sizeof(*device));
   		file << endl;
	}
	file.close();

	#ifdef _DEBUG
		_onexit(_CrtDumpMemoryLeaks);
	#endif
	return 0;
}
void ChangeTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin){
	thread thread1(UpdateTemp, ref(end), ref(House), ref(temp), ref(TempMax), ref(TempMin));
	thread1.detach();
}

void UpdateTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin){
	while(end){
		for(Device* device : House){
			if((*device).GetType() == "Thermostat" && dynamic_cast<Thermostat*>(device)->GetOnOff()){
				for(Device* device : House){
					if((*device).GetType() == "Radiator" && dynamic_cast<Radiator*>(device)->GetOnOff()){
						if(temp != TempMax){
							temp += 1;
						}
					}
				}
			}
		}
		if(temp != TempMin){
			temp -= 1;
		}
		sleep(1800);
	}
}

void menu(bool end, list<Device*>& House, int& temp, DeviceFact& Factory){
	bool exit = true;
	void display(list<Device*> House);
	Device* find(list<Device*> House, string name);
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
				display(House);
				exit = continues();
				break;
			}
			case '2':{
				House.sort([](const Device* first, const Device* second) { return first->GetName() < second->GetName(); });
				display(House);
				exit = continues();
				break;
			}
			
			case '3':{
				House.sort([](const Device* first, const Device* second) { 
					if(typeid(first) == typeid(second) && first->GetName() < second->GetName()){
						return true; 
					}
					return typeid(first).name() < typeid(second).name(); 
				});
				display(House);
				exit = continues();
				break;
			}
			case '4':{
				cout << "Enter device name : " << flush;
				string name;
				cin >> name;
				Device* current = find(House, name);
				exit = continues();
				break;
			}
			case '5':{
				House.push_front(Add(end, temp, Factory));
				(dynamic_cast<Light*>(House.front()))->ChangeOnOff();
				exit = continues();
				break;
			}
			case '6':{
				end = false;
				exit = false;
				break;
			}
			default:{
				cout << "Enter 1,2,3,4,5,6 \n";
				break;
			}
		}
	}
}
void display(list<Device*> House){
	list<Device*>::iterator it(House.begin());
	while (it!=House.end()){
		cout << (*(it++));
	}
}
Device* find(list<Device*> House, string name){
	list<Device*>::iterator it = find_if(House.begin(), House.end(), [&name](const Device* current) {return current->GetName() == name;});
	return *(it);
}

Device* Add(bool& end, int& temp, DeviceFact& Factory){
	bool exit = true;
	string name;
	string type;
	cout << "Select Device \n"
		 << "1: Light \n"
		 << "2: Plug \n"
		 << "3: Radiator \n"
		 << "4: Speaker \n"
		 << "5: Temperature and humidity sensor \n"
		 << "6: Thermostat \n";
		while(true){
			cin >> type;
			bool test = type != "1";
			if(type != "1" && type != "2" && type != "3" && type != "4" && type != "5" && type != "6"){
				cout << "Enter 1,2,3,4,5,6 \n";
			}else{
				break;
			}
		}
	cout << "Enter name for the device \n";
	cin >> name;
	return Factory.createDevice(stoi(type), name, end, temp);
}

bool continues(){
	string answer;
	cout << "Would you like to go back to the menu Y/N \n";
	while(true){
		cin >> answer;
		if(toupper(answer.c_str()[0]) == 'N'){
			return false;
		}else if(toupper(answer.c_str()[0]) != 'Y'){
			cout << "Enter Y/N \n";
		}else{
			break;
		}
	}
	return true;
}
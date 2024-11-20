#include <list>
#include <algorithm>
#include "Light.h"
#include "Plug.h"
#include "Radiator.h"
#include "Speaker.h"
#include "TempHum.h"
#include "Thermostat.h"

void ChangeTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin);
void UpdateTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin);
void menu(bool end, bool NotEnd, list<Device*> House);

int main(){
	bool end = true;
	bool NotEnd = false;
	int temp = 5;
	int TempMax = 30;
	int TempMin = 5;
	list<Device*> House;
	ChangeTemp(end, House, temp, TempMax, TempMin);
	menu(end, NotEnd, House);
	
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
			if(typeid(*device) == typeid(Thermostat) && dynamic_cast<Thermostat*>(device)->GetOnOff()){
				for(Device* device : House){
					if(typeid(*device) == typeid(Radiator) && dynamic_cast<Radiator*>(device)->GetOnOff()){
							if(temp != TempMax){
								temp += 2;
							}
					}
				}
			}
		}
		if(temp != TempMin){
			temp -= 1;
		}
	}
}

void menu(bool end, bool NotEnd, list<Device*> House){
		void display(list<Device*> House);
		Device* find(list<Device*> House, string name);
		string UserInput;
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
			break;
		}
		case '2':{
			House.sort([](const Device* first, const Device* second) { return first->GetName() < second->GetName(); });
			display(House);
			break;
		}
		
		case '3':{
			House.sort([](const Device* first, const Device* second) { 
				if(first->GetType() == second->GetType() && first->GetName() < second->GetName()){
					return true; 
				}
				return first->GetType() < second->GetType(); 
			});
			display(House);
			break;
		}
		case '4':{
			cout << "Enter device name : " << flush;
			string name;
			cin >> name;
			Device* current = find(House, name);
			break;
		}
		case '5':{
			
			break;
		}
		case '6':{
			while(true){
				if(!NotEnd && end){
					end = false;
					break;
				}
			}
			break;
		}
		default:{

		}
	}
}
void display(list<Device*> House){
	list<Device*>::iterator it(House.begin());
	while (it!=House.end()){
		cout << *(it++);
	}
}
Device* find(list<Device*> House, string name){
	list<Device*>::iterator it = find_if(House.begin(), House.end(), [&name](const Device* current) {return current->GetName() == name;});
	return *(it);
}
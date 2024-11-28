#pragma once
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

class House{
    public:
            inline House(int TempMax, int TempMin);
            inline void ChangeEnd(){end = !end;};
            inline int GetSize(){return devices.size();};
			inline void push(Device* device){devices.push_front(device);};
            void UpdateTemp();
            void display();
            void NameSort();
            void TypeSort();
            Device* find(string name);
            void Add();
            bool continues();

    private:
        list<Device*> devices;
        bool end;
        int temp;
        int TempMax;
        int TempMin;
        DeviceFact Factory;
};


House::House(int TempMax, int TempMin) : TempMax(TempMax), TempMin(TempMin), temp((TempMax + TempMin) / 2){
        thread thread1(&House::UpdateTemp, this); thread1.detach();
}
void House::UpdateTemp(){
	while(end){
		for(Device* device : devices){
			if(typeid(*device) == typeid(Thermostat) && dynamic_cast<Thermostat*>(device)->GetOnOff()){
				for(Device* device : devices){
					if(typeid(*device) == typeid(Radiator) && dynamic_cast<Radiator*>(device)->GetOnOff()){
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
		this_thread::sleep_for(1800s);
	}
}

void House::display(){
	list<Device*>::iterator it(devices.begin());
	while (it!=devices.end()){
		cout << (*(it++));
	}
}

Device* House::find(string name){
	list<Device*>::iterator it = find_if(devices.begin(), devices.end(), [&name](const Device* current) {return current->GetName() == name;});
    if((**(it)).GetName() != name){
        return nullptr;
    }
	return *(it);
}

void House::Add(){
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
	devices.push_front(Factory.createDevice(stoi(type), name, end, temp));
}

bool House::continues(){
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

void House::NameSort(){
    devices.sort([](const Device* first, const Device* second) { 
        return first->GetName() <= second->GetName(); 
    });
}

void House::TypeSort(){
    devices.sort([](const Device* first, const Device* second) { 
        if(typeid(first) == typeid(second) && first->GetName() < second->GetName()){
            return true; 
        }
        return typeid(first).name() < typeid(second).name(); 
    });
}
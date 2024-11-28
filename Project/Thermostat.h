#pragma once
#include "OneClick.h"
#include <iostream>
#include <string>
using namespace std;

class Thermostat : public OneClick::Schedule, public Device{
    public:
            inline Thermostat(bool& end) : Schedule(end){};
            Thermostat(string name, bool& end);
            void HeatingBoost();
            void DisplayFunctions() override;
};

Thermostat::Thermostat(string name, bool& end) : Schedule(end){
        this->SetName(name); 
        this->SetType("Thermostat");
}

void Thermostat::HeatingBoost(){
    SetOnOff(true);
    this_thread::sleep_for(3600s);
    SetOnOff(false);
}

void Thermostat::DisplayFunctions(){
    bool Another();
    bool isNumber(const string input);
    string IsOnOff;
    string UserInput;
    bool end = true;
    if(GetOnOff()){
        IsOnOff = "ON";
    }else{
        IsOnOff = "OFF";
    }
    cout << *this;
    cout << "And is currently: " << IsOnOff << "\n";
         if(GetSchedule()){
            cout << "Is schedule starts at " << GetStart() << ":00 and last for " << GetLength() << " hours \n";
         }
    cout << "Its functions are: \n"
         << "1: Switch On or Off \n"
         << "2: Set/Replace a schedule \n"
         << "3: Delete Schedule if there is one \n"
         << "4: Exit Menu";

    while(end){
        cin >> UserInput;
        switch(UserInput[0]) {
            case '1':{
                ChangeOnOff();
                if(!Another()){
                    end = false;
                }
                break;
            }
            case '2':{
                int start;
                int length;
                string NewUserInput;
                cout << "Enter start time eg (1900): ";
                cin >> NewUserInput;
                while(true){
                    if(NewUserInput.length() == 4 && isNumber(NewUserInput)){
                        for(int i = 3; i > 1; i--){
                            NewUserInput.erase(NewUserInput.begin() + i);
                        }
                        start = atoi((char*)NewUserInput.data());
                        break;
                    }
                }
                while(true){
                    cout << "Enter length in hours: ";
                    cin >> NewUserInput;
                    if(isNumber(NewUserInput)){
                        length = atoi((char*)NewUserInput.data());
                        break;
                    }
                }
                StartSchedules(start, length);
            }
            case '3':{
                if(!GetSchedule()){
                    DeleteSchedule();
                }
            }
            case '4':{
                end = false;
            }
            default:{
                cout << "Enter 1,2,3,4:";
                cin >> UserInput;
            }
        }
    }
}

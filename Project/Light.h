#pragma once
#include "OneClick.h"
#include <iostream>
#include <string>
using namespace std;

class Light : public OneClick::SleepTimer{
        public:
                inline Light(string name, bool& NotEnd) : SleepTimer(NotEnd), brightness(0){this->SetName(name);};
                inline Light(bool& NotEnd) : SleepTimer(NotEnd), brightness(0){};
                inline void setBrightness(int brightness){this->brightness = brightness;};
                void DisplayFunctions() override;
        private:
                int brightness;
};


void Light::DisplayFunctions(){
    bool Another();
    string IsOnOff;
    string UserInput;
    bool end = true;
    if(GetOnOff()){
        IsOnOff = "ON";
    }else{
        IsOnOff = "OFF";
    }
    cout << *this;
    cout << "Its brightness is : " << brightness << "\n"
         << "And is currently: " << IsOnOff << "\n"
         << "Its functions are: \n"
         << "1: Change brightness \n"
         << "2: Switch On or Off \n"
         << "3: Exit Menu";

    while(end){
        cin >> UserInput;
        switch(UserInput[0]) {
            case '1':{
                int NewBrightness;
                cout << "Enter new brightness";
                cin >> NewBrightness;
                if(!Another()){
                    end = false;
                }
                break;
            }
            case '2':{
                ChangeOnOff();
                if(!Another()){
                    end = false;
                }
                break;
            }
            case '3':{
                end = false;
            }
            default:{
                cout << "Enter 1,2,3:";
                cin >> UserInput;
            }
        }
    }
}

bool Another(){
    string UserInput;
    cout << "Wou;d you like another option (Y/N):";
    cin >> UserInput;
    while(true){
            if((char)toupper(UserInput[0]) == 'Y'){
                return true;
            }else if((char)toupper(UserInput[0]) == 'N'){
                return false;
            }else{
                cout << "Enter Y/N";
                cin >> UserInput;
            }
    }
}
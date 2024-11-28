#pragma once
#include "OneClick.h"

class Radiator : public OneClick::SleepTimer, public OneClick::Schedule{
    public:
        Radiator(string name, int& temp, bool& end);
        Radiator(int& temp, bool& end);
        inline int& GetTemp(){return temp;};
        void DisplayFunctions() override;

    private:
        int& temp;
};

Radiator::Radiator(string name, int& temp, bool& end) : temp(temp) , Schedule(end){
    SetName(name);
    this->SetType("Radiator"); 
}

Radiator::Radiator(int& temp, bool& end) : temp(temp) , Schedule(end){}


#include "Radiator.h"

void Radiator::DisplayFunctions(){
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
         << "4: Sleep Timer \n"
         << "5: Exit Menu";

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
                int length;
                string NewUserInput;
                while(true){
                    cout << "Enter how long the device should be on for in seconds: ";
                    cin >> NewUserInput;
                    if(isNumber(NewUserInput)){
                        length = atoi((char*)NewUserInput.data());
                        break;
                    }
                }
                call(length);
            }
            case '5':{
                end = false;
            }
            default:{
                cout << "Enter 1,2,3,4:";
                cin >> UserInput;
            }
        }
    }
}

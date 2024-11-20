#pragma once
#include "OneClick.h"
#include "LiveHistoric.h"

class Plug : public OneClick::SleepTimer, public OneClick::Schedule, public LiveHistoric<int>{
    public:
        Plug(string name, int HistoricMax, float sensitivity, bool& end, int power, bool& NotEnd);
        void DisplayFunctions() override;
        
    private:
        void incrementLive() override;
        int power;
};

Plug::Plug(string name, int HistoricMax, float sensitivity, bool& end, int power, bool& NotEnd) : power(power), LiveHistoric(HistoricMax, sensitivity, end), Schedule(end), SleepTimer(NotEnd){
    this->SetName(name);
    UpdateLive();
}

void Plug::incrementLive(){
    srand(time(0));
    while(LiveHistoric::GetEnd()){
        if(this->OneClick::GetOnOff()){
            if(rand() % 2 == 0){
                int temp = (power + rand() % 3);
                this->SetLive(temp);
            }else{
                int temp = (power - rand() % 3);
                this->SetLive(temp);
            }
        }
    }
}

void Plug::DisplayFunctions(){
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
    cout << this;
    cout << "Its current power usage is : " << GetLive() << "\n"
         << "And is currently: " << IsOnOff << "\n";
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

bool isNumber(const string input){
    for (char digit : input) {
        if (!isdigit(digit)) {
            return false;
        }
    }
    return true;
}
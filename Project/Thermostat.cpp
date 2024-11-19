#include "Thermostat.h"

void Thermostat::HeatingBoost(){
    SetOnOff(true);
    sleep(3600);
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
    cout << this;
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
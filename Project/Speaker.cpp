#include "Speaker.h"

void Speaker::DisplayFunctions(){
    bool Another();
    string IsOnOff;
    string UserInput;
    bool end = true;
    if(GetOnOff()){
        IsOnOff = "ON";
    }else{
        IsOnOff = "OFF";
    }
    cout << this;
    cout << "Its Volume is : " << Volume << "\n"
         << "And is currently: " << IsOnOff << "\n"
         << "Its functions are: \n"
         << "1: Volume Up \n"
         << "2: Volume Down \n"
         << "3: Switch On or Off \n"
         << "4: Exit Menu";

    while(end){
        cin >> UserInput;
        switch(UserInput[0]) {
            case '1':{
                volumeUp;
            }
            case '2':{   
                volumeDown();
            }
            case '3':{
                ChangeOnOff();
                if(!Another()){
                    end = false;
                }
                break;
            }
            case '4':{
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
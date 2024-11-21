#pragma once
#include "OneClick.h"

class Speaker : public OneClick{
        public:
                inline Speaker(string name) : Volume(0), MaxVolume(10){this->SetName(name);};
                inline Speaker(string name, int Volume, int MaxVolume, bool OnOff);
                inline void setVolume(int Volume){this->Volume = Volume;};
                inline void volumeUp(){if(Volume != MaxVolume) Volume++;};
                inline void volumeDown(){if(Volume != 0) Volume--;};
                void DisplayFunctions() override;
                list<string> GetValues() override;

        private:
                int Volume;
                int MaxVolume;
};

Speaker::Speaker(string name, int Volume, int MaxVolume, bool OnOff) : Volume(Volume), MaxVolume(MaxVolume){
    this->SetName(name); 
    SetOnOff(OnOff);
}

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
    cout << *this;
    cout << "Its Volume is : " << Volume << "\n"
         << "And it's currently: " << IsOnOff << "\n"
         << "Its functions are: \n"
         << "1: Volume Up \n"
         << "2: Volume Down \n"
         << "3: Switch On or Off \n"
         << "4: Exit Menu";

    while(end){
        cin >> UserInput;
        switch(UserInput[0]) {
            case '1':{
                volumeUp();
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

list<string> Speaker::GetValues(){
    list<string> temp;
    temp.push_front("speaker");
    temp.push_front(GetName());
    temp.push_front(to_string(Volume));
    temp.push_front(to_string(MaxVolume));
    temp.push_front(to_string(GetOnOff()));
    return temp;
}
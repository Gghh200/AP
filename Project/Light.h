#pragma once
#include "OneClick.h"
#include <iostream>
#include <string>
using namespace std;

class Light : public OneClick::SleepTimer{
        public:
                inline Light(string name, bool& NotEnd) : SleepTimer(NotEnd){this->SetName(name);};
                inline Light(string name, int brightness, bool& NotEnd);
                inline void setBrightness(int brightness){this->brightness = brightness;};
                void DisplayFunctions() override;
                list<string> GetValues() override;
        private:
                int brightness;
};

Light::Light(string name, int brightness, bool& NotEnd) : brightness(brightness), SleepTimer(NotEnd){
        this->SetName(name); 
        SetOnOff(NotEnd);
}

list<string> Light::GetValues(){
    list<string> temp;
    temp.push_front("Light");
    temp.push_front(GetName());
    temp.push_front(to_string(brightness));
    temp.push_front(to_string(GetOnOff()));
    return temp;
}

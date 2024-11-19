#pragma once
#include "OneClick.h"
#include <iostream>
#include <string>
using namespace std;

class Light : public OneClick::SleepTimer{
        public:
                inline Light(string name, bool& NotEnd) : SleepTimer(NotEnd){this->SetName(name);};
                inline void setBrightness(int brightness){this->brightness = brightness;};
                void DisplayFunctions() override;
        private:
                int brightness;
};

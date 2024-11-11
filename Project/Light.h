#pragma once
#include "OneClick.h"
#include <iostream>
#include <string>
using namespace std;

class Light : public OneClick::SleepTimer{
        public:
                Light(string name, bool& end) : SleepTimer(name){this->name = name;};
                inline void setBrightness(int brightness){this->brightness = brightness;};
        private:
                int brightness;
};

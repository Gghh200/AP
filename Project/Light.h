#include "OneClick.h"
#include <iostream>
#include <string>
using namespace std;

class Light : public OneClick{
        public:
                Light(string name, int SleepStart, int SleepLength, bool& end) : OneClick(name){this->name = name;};
                inline void setBrightness(int brightness){this->brightness = brightness;};
        private:
                int brightness;
};

#include "OneClick.h"
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <thread>
using namespace std;

class Light : public OneClick{
        public:
                Light(string name, int SleepStart, int SleepLength, bool& end);
                inline void setBrightness(int brightness){ this->brightness = brightness;};
                void changeSleep(int start);
                void changeSleep(int start, int length);
                void timeCheck(bool& end);
                void timeChecks(bool& end);
        private:
                int brightness;
                int SleepStart;
                int SleepLength;
};

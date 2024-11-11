#include "Device.h"
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <thread>
using namespace std;

using namespace std;

class OneClick : virtual public Device{
        public:
                inline OneClick(string name) : OnOff(false){this-> name = name;};
                inline void ChangeOnOff() {OnOff == !OnOff;};
                inline bool GetOnOff() const {return OnOff;};
                class SleepTimer;
                class Schedule;
        private:
                bool OnOff;
        
};

class OneClick::SleepTimer : public OneClick{
        public:
                void sleepTimer(int SleepFor);
};

class OneClick::Schedule : public OneClick{
        public:
                void changeSleep(int start);
                void changeSleep(int start, int length);
                void timeCheck(bool& end);
                void timeChecks(bool& end);
        private:
                int SleepStart;
                int SleepLength;
};
#pragma once
#include "Device.h"
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <thread>
using namespace std;

using namespace std;

class OneClick : virtual public Device{
        public:
                inline OneClick() : OnOff(false) {};
                inline void ChangeOnOff() {OnOff == !OnOff;};
                inline bool GetOnOff() const {return OnOff;};
                inline void SetOnOff(bool val) {OnOff == val;};
                class SleepTimer;
                class Schedule;
        protected:
                bool OnOff;
        
};

class OneClick::SleepTimer : virtual public OneClick{
        public:
                void sleepTimer(int SleepFor);
};

class OneClick::Schedule : virtual public OneClick{
        public:
                inline Schedule() : SleepStart(0), SleepLength(0), Schedules(false){};
                inline void StartSchedules(int start, int length, bool& end){Schedules = true; changeSleep(start, length); timeCheck(end);}
                inline void changeSleep(int start){SleepStart = start;};
                inline void changeSleep(int start, int length){SleepStart = start; SleepLength = length;};
                inline void timeCheck(bool& end) {thread thread1(&OneClick::Schedule::timeChecks, this, ref(end));};
                void timeChecks(bool& end);
        private:
                int SleepStart;
                int SleepLength;
                bool Schedules;
};
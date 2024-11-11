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
                inline OneClick() : OnOff(false) {this-> name = "NULL";};
                inline OneClick(string name) : OnOff(false){this-> name = name;};
                inline void ChangeOnOff() {OnOff == !OnOff;};
                inline bool GetOnOff() const {return OnOff;};
                class SleepTimer;
                class Schedule;
        private:
                bool OnOff;
        
};

class OneClick::SleepTimer : virtual public OneClick{
        public:
                inline SleepTimer(string name) : OneClick(name){};
                void sleepTimer(int SleepFor);
};

class OneClick::Schedule : virtual public OneClick{
        public:
                inline Schedule(string name) : OneClick(name) {};
                inline Schedule(string name, int start, int length) : OneClick(name){StartSchedules(start, length);};
                inline void StartSchedules(int start, int length){Schedules = true; changeSleep(start, length);}
                inline void changeSleep(int start){SleepStart = start;};
                inline void changeSleep(int start, int length){SleepStart = start; SleepLength = length;};
                inline void timeCheck(bool& end) {thread thread1(&OneClick::Schedule::timeChecks, this, ref(end));};
                void timeChecks(bool& end);
        private:
                int SleepStart;
                int SleepLength;
                bool Schedules;
};
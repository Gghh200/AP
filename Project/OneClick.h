#pragma once
#include "Device.h"
#include <iostream>
#include <ctime>
#include <thread>
using namespace std;

using namespace std;

class OneClick{
        public:
                inline void ChangeOnOff() {OnOff = !OnOff;};
                inline bool GetOnOff() const {return OnOff;};
                class SleepTimer;
                class Schedule;

        protected:
                inline OneClick() : OnOff(false) {};
                inline void SetOnOff(bool val) {OnOff == val;};
                
        private:
                bool OnOff;
        
};

class OneClick::SleepTimer : virtual public OneClick{
        protected:
                inline void call(int SleepFor);
        private:
                inline void calls(int SleepFor);
};

inline void OneClick::SleepTimer::call(int SleepFor){
        thread thread1(&OneClick::SleepTimer::calls, this, SleepFor);
        thread1.detach();
}

inline void OneClick::SleepTimer::calls(int SleepFor){
    OnOff = true;
    this_thread::sleep_for(chrono::seconds(SleepFor));
    OnOff = false;
}


class OneClick::Schedule : virtual public OneClick{
        public:
                inline Schedule(bool& end) : SleepStart(0), SleepLength(0), Schedules(false), end(end){};
                inline void StartSchedules(int start, int length){Schedules = true; changeSleep(start, length); timeCheck();}
                inline void changeSleep(int start, int length){SleepStart = start; SleepLength = length;};
                inline void timeCheck() {thread thread1(&OneClick::Schedule::timeChecks, this, ref(end));};
                inline void DeleteSchedule(){Schedules = false;};
                inline bool GetSchedule(){return Schedules;};
                inline int GetStart(){return SleepStart % 3600 / 3600;};
                inline int GetLength(){return SleepLength % 3600 / 3600;};
                inline bool& GetEnd(){return end;};
                void timeChecks(bool& end);
        private:
                int SleepStart;
                int SleepLength;
                bool Schedules;
                bool& end;
};

void OneClick::Schedule::timeChecks(bool& end){
    while(Schedules && end){
        if((time(0) % 3600 ) / 3600 == SleepStart){
            ChangeOnOff();
            this_thread::sleep_for(chrono::seconds(SleepLength * 3600));
        }else{
            this_thread::sleep_for(3600s);
        }
    }
}
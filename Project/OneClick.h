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
                inline SleepTimer(bool& NotEnd) : NotEnd(NotEnd){};
                inline void call(int SleepFor);
        private:
                inline void calls(int SleepFor, bool& NotEnd);
                bool& NotEnd;
};

inline void OneClick::SleepTimer::call(int SleepFor){
        NotEnd = true;
        thread thread1(&OneClick::SleepTimer::calls, this, SleepFor, ref(NotEnd));
        thread1.detach();
}

inline void OneClick::SleepTimer::calls(int SleepFor, bool& NotEnd){
    OnOff = true;
    sleep(SleepFor);
    OnOff = false;
    NotEnd = false;
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
            sleep(SleepLength * 3600);
        }else{
            sleep(3600);
        }
    }
}
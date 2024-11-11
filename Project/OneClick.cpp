#include "OneClick.h"

void OneClick::SleepTimer::sleepTimer(int SleepFor){
    OnOff = true;
    sleep(SleepFor);
    OnOff = false;
}

void OneClick::Schedule::changeSleep(int start){
    SleepStart = start;
}

void OneClick::Schedule::changeSleep(int start, int length){
    SleepStart = start;
    SleepLength = length;
}

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
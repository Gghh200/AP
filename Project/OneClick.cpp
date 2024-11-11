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

void OneClick::Schedule::timeCheck(bool& end){
    thread thread1(&OneClick::Schedule::timeChecks, this, ref(end));
}

void OneClick::Schedule::timeChecks(bool& end){
    while(end){
        if((time(0) % 3600 ) / 3600 == SleepStart){
            ChangeOnOff();
            sleep(SleepLength * 3600);
        }else{
            sleep(3600);
        }
    }
}
#include "Light.h"

Light::Light(string name, int SleepStart, int SleepLength, bool& end) : OneClick(name), SleepStart(SleepStart), SleepLength(SleepLength), Device(name){

}

void Light::changeSleep(int start){
    SleepStart = start;
}

void Light::changeSleep(int start, int length){
    SleepStart = start;
    SleepLength = length;
}

void Light::timeCheck(bool& end){
    thread thread1(timeChecks, end);
}

void Light::timeChecks(bool& end){
    while(end){
        if((time( 0 ) % 3600 ) / 3600 == SleepStart){
            ChangeOnOff();
            sleep(SleepLength * 3600);
        }else{
            sleep(3600);
        }
    }
}

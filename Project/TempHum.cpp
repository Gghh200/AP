#include "TempHum.h"

void TempHum::incrementLive(bool& end){
    srand(time(0));
    int humidity = 78;
    while(end){
        if(rand() % 2 == 0){
            humidity += rand() % 3;
        }else{
            humidity -= rand() % 3;
        }
        int value[2] = {temp, humidity};
        this->SetLive(value);
    }
}
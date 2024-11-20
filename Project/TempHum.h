#pragma once
#include "LiveHistoric.h"
#include <array>
#include <iostream>
using namespace std;

class TempHum : public LiveHistoric<array<int, 2>>{
    public:
        TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp);
        void DisplayFunctions() override;
        
    private:
        void incrementLive() override;
        int& temp;
        int humidity;
        int humidityMax;
        int humidityMin;
};
TempHum::TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp) : humidityMax(100), humidityMin(60), humidity(78), temp(temp), LiveHistoric(HistoricMax, sensitivity, end){
    this->SetName(name);
    this->UpdateLive();
    array<int, 2> value = {temp, humidityMin};
    SetLive(value);
}


void TempHum::incrementLive(){
    srand(time(0));
    while(GetEnd()){
        if(rand() % 2 == 0 && humidity <= humidityMin){
            humidity += rand() % 3;
        }else{
            humidity -= rand() % 3;
        }
        array<int, 2> value = {temp, humidity};
        this->SetLive(value);
    }
}

void TempHum::DisplayFunctions(){
    cout << this
         << "The current temp is: " << (GetLive()[0]) << "\n"
         << "The current Humidity is: " << GetLive()[1] << "\n"
         << "This window will close in 10 seconds \n";
    sleep(10);
}
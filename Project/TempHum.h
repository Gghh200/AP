#pragma once
#include "LiveHistoric.h"
#include <array>
#include <iostream>
using namespace std;

class TempHum : public LiveHistoric<array<int, 2>>{
    public:
        TempHum(bool& end, int& temp);
        TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp, int humidity, int humidityMax, int humidityMin);
        void DisplayFunctions() override;
        
    private:
        void incrementLive() override;
        int& temp;
        int humidity;
        int humidityMax;
        int humidityMin;
};

TempHum::TempHum(bool& end, int& temp) : humidityMax(0), humidityMin(0), humidity(0), temp(temp), LiveHistoric(0, 0, end){};

TempHum::TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp, int humidity, int humidityMax, int humidityMin) : humidityMax(humidityMax), humidityMin(humidityMin), humidity(humidity), temp(temp), LiveHistoric(HistoricMax, sensitivity, end){
    this->SetName(name);
    this->SetType("TempHum"); 
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
    cout << *this
         << "The current temp is: " << (GetLive()[0]) << "\n"
         << "The current Humidity is: " << GetLive()[1] << "\n"
         << "This window will close in 10 seconds \n";
    sleep(10);
}

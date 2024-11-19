#pragma once
#include "LiveHistoric.h"

class TempHum : public LiveHistoric<int*>{
    public:
        TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp);
        void DisplayFunctions() override;
        
    private:
        void incrementLive();
        int& temp;
        int humidity;
        int humidityMax;
        int humidityMin;
};
TempHum::TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp) : humidityMax(100), humidityMin(60), humidity(78), temp(temp), LiveHistoric(HistoricMax, sensitivity, end){
    this->SetName(name);
    this->UpdateLive();
    SetLive(new int[2]{0,0});
}


void TempHum::incrementLive(){
    srand(time(0));
    while(GetEnd()){
        if(rand() % 2 == 0 && humidity <= humidityMin){
            humidity += rand() % 3;
        }else{
            humidity -= rand() % 3;
        }
        int value[2] = {temp, humidity};
        this->SetLive(value);
    }
}

void TempHum::DisplayFunctions(){
    cout << this
         << "The current temp is: " << GetLive()[0] << "\n"
         << "The current Humidity is: " << GetLive()[1] << "\n"
         << "This window will close in 10 seconds \n";
    sleep(10);
}
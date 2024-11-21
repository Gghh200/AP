#pragma once
#include "LiveHistoric.h"
#include <array>
#include <iostream>
using namespace std;

class TempHum : public LiveHistoric<array<int, 2>>{
    public:
        TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp);
        TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp, int humidity, int humidityMax, int humidityMin);
        void DisplayFunctions() override;
        list<string> GetValues() override;
        
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
    cout << *this
         << "The current temp is: " << (GetLive()[0]) << "\n"
         << "The current Humidity is: " << GetLive()[1] << "\n"
         << "This window will close in 10 seconds \n";
    sleep(10);
}

list<string> TempHum::GetValues(){
    list<string> temp;
    temp.push_front("TempHum");
    temp.push_front(GetName());
    temp.push_front(to_string(humidity));
    temp.push_front(to_string(humidityMax));
    temp.push_front(to_string(humidityMin));
    for(int i = GetHistoric().size(); i > 0; i--){
        array<int, 2> arr = GetHistoric().front();
        GetHistoric().pop();
        temp.push_front(to_string(arr[0]));
        temp.push_front(to_string(arr[1]));
    }
    return temp;
}
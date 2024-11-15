#pragma once
#include "LiveHistoric.h"

class TempHum : public LiveHistoric<int*>{
    public:
        TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp);
        
    private:
        void incrementLive(bool& end);
        int& temp;
};
TempHum::TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp) : temp(temp), LiveHistoric(HistoricMax, sensitivity, end){
    this->SetName(name);
    this->UpdateLive(end);
    SetLive(new int[2]{0,0});
}
#pragma once
#include "LiveHistoric.h"

class TempHum : public LiveHistoric<int[2]>{
    public:
        TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp);
        
    private:
        void incrementLive(bool& end);
        int& temp;
};
TempHum::TempHum(string name, int HistoricMax, float sensitivity, bool& end, int& temp) : temp(temp), LiveHistoric(0, HistoricMax, sensitivity, end){
    this->SetName(name);
    this->UpdateLive(end);
}
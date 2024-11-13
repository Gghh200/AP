#pragma once
#include "OneClick.h"
#include "LiveHistoric.h"

class Plug : public OneClick::SleepTimer, public OneClick::Schedule, public LiveHistoric<int>{
    public:
        Plug(string name, int HistoricMax, float sensitivity, bool& end, int power);
        
    private:
        void incrementLive(bool& end);
        int power;
};
Plug::Plug(string name, int HistoricMax, float sensitivity, bool& end, int power) : power(power), LiveHistoric(0, HistoricMax, sensitivity, end){
    this->SetName(name);
    this->UpdateLive(end);
}
#pragma once
#include "OneClick.h"
#include "LiveHistoric.h"

class Plug : public OneClick::SleepTimer, public OneClick::Schedule, public LiveHistoric<int>{
    public:
        Plug(string name, int HistoricMax, float sensitivity, bool& end, int power);
        
    private:
        void incrementLive(bool& end) override;
        int power;
};

Plug::Plug(string name, int HistoricMax, float sensitivity, bool& end, int power) : power(power), LiveHistoric(HistoricMax, sensitivity, end){
    
    this->SetName(name);
    UpdateLive(end);
    this->SetType("Plug");
}


void Plug::incrementLive(bool& end){
    srand(time(0));
    while(end){
        if(this->GetOnOff()){
            if(rand() % 2 == 0){
                this->SetLive(power + rand() % 3);
            }else{
                this->SetLive(power - rand() % 3);
            }
        }
    }
}

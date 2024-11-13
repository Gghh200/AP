#pragma once
#include "OneClick.h"

class Radiator : public OneClick::SleepTimer, public OneClick::Schedule{
    public:
        Radiator(string name, int& temp);
        inline int& GetTemp(){return temp;};
    private:
        int& temp;
};
Radiator::Radiator(string name, int& temp) : temp(temp){
    this->SetName(name);
}
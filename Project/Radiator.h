#pragma once
#include "OneClick.h"

class Radiator : public OneClick::SleepTimer, public OneClick::Schedule{
    public:
        Radiator(string name, int& temp, bool& end, bool& NotEnd);
        inline int& GetTemp(){return temp;};
        void DisplayFunctions() override;
    private:
        int& temp;
};
Radiator::Radiator(string name, int& temp, bool& end, bool& NotEnd) : temp(temp) , Schedule(end), SleepTimer(NotEnd){
    SetName(name);
}
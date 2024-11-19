#pragma once
#include "OneClick.h"
#include <iostream>
#include <string>
using namespace std;

class Thermostat : public OneClick::Schedule{
        public:
                inline Thermostat(string name, bool& end) : Schedule(end){this->SetName(name);};
                void HeatingBoost();
                void DisplayFunctions() override;
};

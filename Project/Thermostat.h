#pragma once
#include "OneClick.h"
#include <iostream>
#include <string>
using namespace std;

class Thermostat : public OneClick::Schedule{
        public:
                inline Thermostat(string name){this->SetName(name);};
                void HeatingBoost();
};

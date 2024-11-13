#include "Thermostat.h"

void Thermostat::HeatingBoost(){
    SetOnOff(true);
    sleep(3600);
    SetOnOff(false);
}
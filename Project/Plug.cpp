#include "Plug.h"

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
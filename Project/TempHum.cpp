#include "TempHum.h"


void TempHum::DisplayFunctions(){
    cout << this
         << "The current temp is: " << GetLive()[0] << "\n"
         << "The current Humidity is: " << GetLive()[1] << "\n"
         << "This window will close in 10 seconds \n";
    sleep(10);
}
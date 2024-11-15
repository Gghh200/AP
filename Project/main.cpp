#include <list>
#include "Light.h"
// #include "Plug.h"
//#include "Radiator.h"
// #include "Speaker.h"
// #include "TempHum.h"
//#include "Thermostat.h"

void ChangeTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin);
void UpdateTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin);

int main(){
	bool end = false;
	bool NotEnd = false;
	int temp = 5;
	int TempMax = 30;
	int TempMin = 5;
	list<Device*> House;
	//ChangeTemp(end, House, temp, TempMax, TempMin);
	Light* test = new Light("Light");
	test->sleepTimer(10, NotEnd);
	while(true){
		if(!NotEnd && !end){
			end = false;
			break;
		}
		sleep(1);
	}
	
	#ifdef _DEBUG
		_onexit(_CrtDumpMemoryLeaks);
	#endif
	return 0;
}
void ChangeTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin){
	thread thread1(UpdateTemp, ref(end), ref(House), ref(temp), ref(TempMax), ref(TempMin));
	thread1.detach();
}

void UpdateTemp(bool& end, list<Device*>& House, int& temp, int& TempMax, int& TempMin){
	while(end){
		for(Device* device : House){
			if(device->GetType() == "Thermostat" && device->GetOnOff()){
				for(Device* device : House){
					if(device->GetType() == "Radiator" && device->GetOnOff()){
							if(temp != TempMax){
								temp += 2;
							}
					}
				}
			}
		}
		if(temp != TempMin){
			temp -= 1;
		}
	}
}


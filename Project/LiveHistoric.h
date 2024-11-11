#include "Device.h"
#include <unistd.h>
#include <queue>
#include <thread>

template <typename T>
class LiveHistoric : virtual public Device{
    public:
        LiveHistoric(string name, int HistoricSize, float sensitivity, int record, int HistoricMax, bool& end);
        ~LiveHistoric();
        static void UpdateLive(bool& end);
        static void Update(bool& end);
        void incrementLive();

    private:
        T* live;
        queue<T*> historic;
        int HistoricMax;
        float sensitivity;
        int record;
        float change;
        string name;
};

template <typename T>
LiveHistoric<T>::LiveHistoric(string name, int historicSize, float sensitivity, int record, int HistoricMax, bool& end) : live(nullptr), sensitivity(sensitivity), record(record)
, HistoricMax(HistoricMax){
    UpdateLive(bool& end);
    this-> name = name;
}

template <typename T>
LiveHistoric<T>::~LiveHistoric(){
    for (queue<T*>::iterator it(historic.begin()); it != historic.end(); it++) {
		delete (*it);
		(*it) = nullptr;
	}
    delete live;
    live = nullptr;
}

template <typename T>
void LiveHistoric<T>::UpdateLive(bool& end){
    thread thread1(Update, end);
}

template <typename T>
void LiveHistoric<T>::Update(bool& end){
    int x = 0;
    while(end){
        incrementLive();
        if(x == record){
            if(historic.size != HistoricMax){
                historic.push(live);
            }
            else{
                historic.pop();
                historic.push(live);
            }
            x = 0;
        }
        sleep(sensitivity);
    }
}

template <typename T>
void LiveHistoric<T>::incrementLive(){
    live++;
}
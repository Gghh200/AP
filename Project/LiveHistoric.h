#pragma once
#include "Device.h"
#include <unistd.h>
#include <queue>
#include <thread>

template <typename T>
class LiveHistoric : virtual public Device{
    protected:
        inline LiveHistoric() : live(NULL), HistoricMax(0), sensitivity(0f);
        LiveHistoric(int live, int HistoricMax, float sensitivity, bool& end);
        ~LiveHistoric();
        inline SetLive(T live){this->live = live};
        inline T GetLive(){return live} const;
        inline queue<T> GetHistoric(){return historic} const;
        inline int GetHistoricMax(){return HistoricMax} const;
        inline int GetSensitivity(){return sensitivity} const;
        static void UpdateLive(bool& end);

    private:
        void Update(bool& end);
        void incrementLive(bool& end);
        T live;
        queue<T> historic;
        int HistoricMax;
        float sensitivity;
};

template <typename T>
LiveHistoric<T>::LiveHistoric(int live, int HistoricMax, float sensitivity, bool& end) : live(live), HistoricMax(HistoricMax), sensitivity(sensitivity){
    UpdateLive(end)
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
    thread thread2(incrementLive(bool& end));
}

template <typename T>
void LiveHistoric<T>::Update(bool& end){
    int x = 0;
    while(end){
        if(historic.size() != HistoricMax){
            historic.push(live);
        }
        else{
            historic.pop();
            historic.push(live);
        }
        x = 0;
        sleep(sensitivity);
    }
}

template <typename T>
void LiveHistoric<T>::incrementLive(bool& end){
    while (end){
        live++;
    }  
}
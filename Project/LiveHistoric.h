#pragma once
#include "Device.h"
#include <unistd.h>
#include <queue>
#include <thread>

template <typename T>
class LiveHistoric : virtual public Device{
    protected:
        inline LiveHistoric() : live(NULL), HistoricMax(0), sensitivity(0){};
        LiveHistoric(int live, int HistoricMax, float sensitivity, bool& end);
        ~LiveHistoric();
        inline void SetLive(T live){this->live = live;};
        inline T* GetLive(){return live;};
        inline queue<T> GetHistoric(){return historic;};
        inline int GetHistoricMax(){return HistoricMax;};
        inline int GetSensitivity(){return sensitivity;};
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
    UpdateLive(end);
}

template <typename T>
LiveHistoric<T>::~LiveHistoric(){
    for (typename queue<T*>::iterator it(historic.begin()); it != historic.end(); it++) {
		delete (*it);
		(*it) = nullptr;
	}
    delete live;
    live = nullptr;
}

template <typename T>
void LiveHistoric<T>::UpdateLive(bool& end){
    thread thread1(&LiveHistoric::Update, ref(end));
    thread thread2(&LiveHistoric::incrementLive, ref(end));
    thread1.detach();
    thread2.detach();
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

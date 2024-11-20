#pragma once
#include "Device.h"
#include <unistd.h>
#include <queue>
#include <thread>

template <typename T>
class LiveHistoric : virtual public Device{
    public:
        void Update();
    protected:
        inline LiveHistoric() : live(NULL), HistoricMax(0), sensitivity(0), end(false){};
        LiveHistoric(int HistoricMax, float sensitivity, bool& end);
        ~LiveHistoric();
        inline void SetLive(T &live){this->live = live;};
        inline bool& GetEnd(){return end;};
        inline T GetLive(){return live;};
        inline queue<T> GetHistoric(){return historic;};
        inline int GetHistoricMax(){return HistoricMax;};
        inline int GetSensitivity(){return sensitivity;};
        void UpdateLive();
        virtual void incrementLive() = 0;

    private:
        T live;
        queue<T> historic;
        int HistoricMax;
        float sensitivity;
        bool& end;
};

template <typename T>
LiveHistoric<T>::LiveHistoric(int HistoricMax, float sensitivity, bool& end) : HistoricMax(HistoricMax), sensitivity(sensitivity), end(end){}

template <typename T>
LiveHistoric<T>::~LiveHistoric(){
    while(!historic.empty()){
        historic.pop();
    }
}

template <typename T>
void LiveHistoric<T>::UpdateLive(){
    thread thread1(&LiveHistoric::Update, this);
    thread thread2(&LiveHistoric::incrementLive, this);
    thread1.detach();
    thread2.detach();
}

template <typename T>
void LiveHistoric<T>::Update(){
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


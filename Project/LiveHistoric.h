#pragma once
#include "Device.h"
#include <queue>
#include <thread>

template <typename T>
class LiveHistoric{
    public:
        void Update();
        inline queue<T> GetHistoric() const {return historic;};
        
    protected:
        inline LiveHistoric() : live(NULL), HistoricMax(0), sensitivity(0), end(false){};
        LiveHistoric(int HistoricMax, int sensitivity, bool& end);
        ~LiveHistoric();
        inline void SetLive(T &live){this->live = live;};
        inline bool& GetEnd() const {return end;};
        inline T GetLive() const {return live;};
        inline void SetHistoric(queue<T> historic){this->historic = historic;};
        inline int GetHistoricMax() const {return HistoricMax;};
        inline void SetHistoricMax(int HistoricMax) {this->HistoricMax = HistoricMax;};
        inline int GetSensitivity() const {return sensitivity;};
        inline void SetSensitivity(int Sensitivity) {this->Sensitivity = Sensitivity;};
        void AddToHistoric(T data);
        void UpdateLive();
        virtual void incrementLive() = 0;

    private:
        T live;
        queue<T> historic;
        int HistoricMax;
        int sensitivity;
        bool& end;
};

template <typename T>
LiveHistoric<T>::LiveHistoric(int HistoricMax, int sensitivity, bool& end) : HistoricMax(HistoricMax), sensitivity(sensitivity), end(end){}

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
        this_thread::sleep_for(chrono::seconds(sensitivity));
    }
}

template <typename T>
void LiveHistoric<T>::AddToHistoric(T data){
    historic.push(data);
}
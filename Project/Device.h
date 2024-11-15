#pragma once
#include <iostream>
#include <string>
using namespace std;

class Device{
        public:
                inline Device() : name("NULL"), type("NULL"){};
                inline string GetName() const {return name;};
                inline void SetName(string name){this->name = name;};
                inline string GetType() const {return type;};
                inline void SetType(string type){this->type = type;};
                virtual bool GetOnOff() const = 0;
        private:
                string name;
                string type;
};

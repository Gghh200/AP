#pragma once
#include <iostream>
#include <string>
using namespace std;

class Device{
        public:
                inline Device() : name(NULL){};
                inline string GetName() const {return name;};
                inline void SetName(string name){this->name = name;};
        private:
                string name;
};

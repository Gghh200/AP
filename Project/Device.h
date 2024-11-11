#pragma once
#include <iostream>
#include <string>
using namespace std;

class Device{
        public:
                inline Device(string name) : name(name){};
                inline Device() : name(NULL){};
                inline string GetName() const {return name;};
        protected:
                string name;
};

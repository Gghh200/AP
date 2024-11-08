#pragma once
#include <iostream>
#include <string>
using namespace std;

class Device{
        public:
                inline Device(string name) : name(name){};
                inline string GetName() const {return name;};
        private:
                string name;
};

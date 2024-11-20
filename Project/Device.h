#pragma once
#include <iostream>
#include <string>
using namespace std;

class Device{
        public:
                inline Device() : name("NULL"){};
                inline string GetName() const {return name;};
                inline void SetName(string name){this->name = name;};
                friend ostream& operator<<(ostream& os, const Device& data);
                virtual void DisplayFunctions() = 0;
        private:
                string name;
};
ostream& operator<<(ostream& os, const Device& data)
{
    os << "Name is " << data.GetName() << "\n";
    return os;
}
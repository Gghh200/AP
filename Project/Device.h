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
                friend ostream& operator<<(ostream& os, const Device& data);
                virtual void DisplayFunctions() = 0;
        private:
                string name;
                string type;
};
ostream& operator<<(ostream& os, const Device& data)
{
    os << "Name is " << data.GetName() << " and it's Type is " << data.GetType() << "\n";
    return os;
}
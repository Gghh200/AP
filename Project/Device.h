#pragma once
#include <iostream>
#include <string>
using namespace std;

class Device{
        public:
                inline Device() : name("NULL"){};
                inline string GetName() const {return name;};
                inline void SetName(string name){this->name = name;};
                inline string GetType() const {return type;};
                inline void SetType(string type){this->type = type;};
                friend ostream& operator<<(ostream& os, const Device& data);
                virtual void DisplayFunctions() = 0;
        private:
                string name;
                string type;
};

ostream& operator<<(ostream& os, const Device& data)
{
    os << "Name is " << data.GetName() << "\n";
    return os;
}
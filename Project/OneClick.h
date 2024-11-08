#include "Device.h"

class OneClick : virtual public Device{
        public:
                inline OneClick(string name) : Device(name), OnOff(false){};
                inline void ChangeOnOff() {OnOff == !OnOff;};
                inline bool GetOnOff() const {return OnOff;};
                
        private:
                bool OnOff;
};

#pragma once
#include "OneClick.h"

class Speaker : public OneClick{
        public:
                inline Speaker(string name){this->SetName(name);};
                inline void setVolume(int Volume){ this->Volume = Volume;};
                inline void volumeUp(){Volume++;};
                inline void volumeDown(){Volume--;};
        private:
                int Volume;
};

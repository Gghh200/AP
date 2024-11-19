#pragma once
#include "OneClick.h"

class Speaker : public OneClick{
        public:
                inline Speaker(string name) : Volume(0), MaxVolume(10){this->SetName(name);};
                inline void setVolume(int Volume){this->Volume = Volume;};
                inline void volumeUp(){if(Volume != MaxVolume) Volume++;};
                inline void volumeDown(){if(Volume != 0) Volume--;};
                void DisplayFunctions() override;
        private:
                int Volume;
                int MaxVolume;
};

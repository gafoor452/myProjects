#ifndef DVDDEVICE_HPP
#define DVDDEVICE_HPP

#include "DeviceAbstract.hpp"
class DVDDevice: public Device{
public:
    DVDDevice(unsigned int c=0):Device(0), movebutton_{c}{}

    void DecreaseVolume() {
        volumelevel_--;
        std::cout<<"DVD Decrease Volume:"<<volumelevel_<<std::endl;
    }

    void ForwardButton() override{
        std::cout<<"Forward Button: "<<++movebutton_<<std::endl;
    }

    void BackwardButton() override{
        std::cout<<"Backward Button:"<<--movebutton_<<std::endl;
    }
private:
    unsigned int movebutton_;

};

#endif
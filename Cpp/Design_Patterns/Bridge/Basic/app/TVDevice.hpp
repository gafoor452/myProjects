#ifndef TVDEVICE_HPP
#define TVDEVICE_HPP
#include "DeviceAbstract.hpp"
class TVDevice: public Device{
public:
    TVDevice(unsigned int c=0):Device(0), channelnumber_{c}{}

    void ForwardButton() override{
        std::cout<<"Changed to Next Channel: "<<++channelnumber_<<std::endl;
    }

    void BackwardButton() override {
        std::cout<<"Changed to Previous Channel: "<<--channelnumber_<<std::endl;
    }
private:
    unsigned channelnumber_;

};

#endif
#ifndef DEVICEABSTRACT_HPP
#define DEVICEABSTRACT_HPP

#include<iostream>
class Device{
public:
    void IncreaseVolume() {
        volumelevel_++;
        std::cout<<"Increase Volume:"<<volumelevel_<<std::endl;
    }
    void DecreaseVolume() {
        volumelevel_--;
        std::cout<<"Decrease Volume:"<<volumelevel_<<std::endl;
    }

    virtual void ForwardButton() = 0;

    virtual void BackwardButton()= 0;

    Device(int n=0):volumelevel_{n}{

    }

    int volumelevel_;
};

#endif
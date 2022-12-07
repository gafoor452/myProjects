#ifndef REMOTEABSTRACT_HPP
#define REMOTEABSTRACT_HPP
#include"DeviceAbstract.hpp"
class RemoteAbstract{
    public:
    RemoteAbstract(Device* device){
        device_ = device;
    }
    void IncreaseVolumeLevel(){
        device_->IncreaseVolume();
    }
    void DecreaseVolumeLevel(){
        device_->DecreaseVolume();
    }
    void ForwardButton(){
        device_->ForwardButton();
    }
    void BackwardButton(){
        device_->BackwardButton();
    }
    Device* device_;
};

#endif
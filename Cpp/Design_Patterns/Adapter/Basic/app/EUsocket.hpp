#ifndef EUSOCKET_HPP
#define EUSOCKET_HPP

#include<iostream>

class EUSocket{
    public:
    virtual void socket_connect() const {
    std::cout<<"EU Socket is connected\n";
    }
    EUSocket(){
        std::cout<<"EU Socket object is created\n";
    }
    virtual ~EUSocket() = default;
};

#endif
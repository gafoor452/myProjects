#ifndef IndianSocket_HPP
#define IndianSocket_HPP

#include<iostream>

class IndianSocket{

public:
    void socketConnect() {
        std::cout<<"Indian Socket is connected\n";
    }

    IndianSocket(){
        std::cout<<"Indian Socket Object is created\n";
    }

};

#endif
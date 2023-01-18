#ifndef IndianPlug_HPP
#define IndianPlug_HPP

#include<iostream>

class IndianPlug{

public:
    void PlugConnect() {
        std::cout<<"Indian Plug is connected to .. ";
    }

    IndianPlug(){
        std::cout<<"Indian Plug Object is created\n";
    }

};

#endif
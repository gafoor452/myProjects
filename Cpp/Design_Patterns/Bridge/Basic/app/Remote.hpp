#ifndef REMOTE_HPP
#define REMOTE_HPP
#include"RemoteAbstract.hpp"

class Remote: public RemoteAbstract{
    public:
    Remote(Device* device):RemoteAbstract(device){
        std::cout<<"RemoteObject is created\n";
    }
};
#endif
#ifndef ADAPTER_HPP
#define ADAPTER_HPP

#include "EUsocket.hpp"
#include "IndianSocket.hpp"

class SocketAdapter : public EUSocket{
    public:
    SocketAdapter(IndianSocket* soc){
        isoc_ = soc;
    }

    void socket_connect() const override{
        std::cout << "Socker Adapter is connected \n";
    }

    private:
    IndianSocket* isoc_;
};

#endif
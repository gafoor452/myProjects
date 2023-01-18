#ifndef ADAPTER_HPP
#define ADAPTER_HPP

#include "EUsocket.hpp"
#include "IndianPlug.hpp"

class SocketAdapter : public EUSocket{
    public:
    SocketAdapter(IndianPlug* soc) : isoc_{soc}{
    }

    void socket_connect() const override{
        isoc_->PlugConnect();
        std::cout << "Socker Adapter \n";
    }

    private:
    IndianPlug* isoc_;
};

#endif
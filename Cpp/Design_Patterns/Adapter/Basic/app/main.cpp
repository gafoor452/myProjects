#include "Adapter.hpp"
#include "EUsocket.hpp"

//Here Charging is the client where it accepts only EUSocket obj
//With the help of Adapter Pattern, Indian Socket connection is adapted to EU Socket obj 
void charging(const EUSocket* socket) {
    socket->socket_connect();
}

int main(){
    
    EUSocket *euSocket = new EUSocket;
    charging(euSocket);

    SocketAdapter *sAd = new SocketAdapter(new IndianSocket);
    charging(sAd);

    delete euSocket;
    delete sAd;
    return 0;
}

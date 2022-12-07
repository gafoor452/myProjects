#include "Remote.hpp"
#include "TVDevice.hpp"
#include "DVDDevice.hpp"
int main(){
    //Remotedevice is created by dervied class by using dervied class of device abstract as a parameter
    RemoteAbstract* TVRemote = new Remote(new TVDevice(10));
    TVRemote->IncreaseVolumeLevel();
    TVRemote->IncreaseVolumeLevel();
    TVRemote->IncreaseVolumeLevel();
    TVRemote->IncreaseVolumeLevel();
    TVRemote->IncreaseVolumeLevel();
    TVRemote->IncreaseVolumeLevel();
    TVRemote->IncreaseVolumeLevel();
    TVRemote->DecreaseVolumeLevel();
    TVRemote->ForwardButton();
    TVRemote->BackwardButton();

    RemoteAbstract* DVDRemote = new Remote(new DVDDevice(0));
    DVDRemote->IncreaseVolumeLevel();
    DVDRemote->IncreaseVolumeLevel();
    DVDRemote->IncreaseVolumeLevel();
    DVDRemote->IncreaseVolumeLevel();
    DVDRemote->IncreaseVolumeLevel();
    DVDRemote->IncreaseVolumeLevel();
    DVDRemote->IncreaseVolumeLevel();
    DVDRemote->DecreaseVolumeLevel();
    DVDRemote->ForwardButton();
    DVDRemote->BackwardButton();

    delete TVRemote;
    delete DVDRemote;

    return 0;
}

#include<iostream>
#include<functional>

typedef short int* ErrorListener;
template<typename Arguments>
class Event {
public:
    typedef std::tuple<Arguments> ArgumentsTuple;
    typedef std::function<void(const Arguments&)> Listener;
    //typedef std::function<void (int&)> Listener;
    
    unsigned int id;

    unsigned int subscribe(Listener listener, ErrorListener errorListener = nullptr);
    Event(): id(0) {}
};

template<typename Arguments_>
unsigned int Event<Arguments_>::subscribe(Listener listener, ErrorListener errorListener) {
id++;
return id;
}


typedef struct{
    char b;
    unsigned int a;
}ST;

using EventData = Event<unsigned short int>; 

int main(void){
    Event< unsigned short int> event1;
    event1.subscribe([]( const unsigned short int &a){
        std::cout << "Gafoor" <<std::endl;
    });
    return 0;
}

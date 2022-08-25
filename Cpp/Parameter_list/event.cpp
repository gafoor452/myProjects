#include<iostream>
#include<functional>
#include<variant>

typedef short int* ErrorListener;
template<typename... Arguments_>
class Event {
public:
    typedef std::tuple<Arguments_...> ArgumentsTuple;
    //typedef std::function<void(const Arguments_&...)> Listener;
    typedef std::function<void(const Arguments_&...)> Listener;
    
    unsigned int id;

    unsigned int subscribe(Listener listener, ErrorListener errorListener = nullptr);
    Event(): id(0) {}
};

template<typename ... Arguments_>
unsigned int Event<Arguments_...>::subscribe(Listener listener, ErrorListener errorListener) {
id++;
return id;
}


typedef struct{
    char b;
    unsigned int a;
}ST;

//Event<unsigned short int, ST> eve; 

int main(void){
    // unsigned int x=7;
    //ST st1{'a', 6};
    //std::variant<unsigned short int,char> x;
    Event< unsigned short int,char> event1;
    event1.subscribe([](const unsigned short int ev1, char ev2){
        std::cout << "Gafoor" <<std::endl;
    });
    return 0;
}

// cannot convert ‘bmw::ic::functions::speed::IcQMSpeedSP2025::SubscribeSpeedAcceleration(std::chrono::milliseconds)::<lambda(const EgoMotionDynamicDataEvent&)>’ 
// to ‘CommonAPI::Event<short unsigned int, short unsigned int, unsigned int, unsigned int, BMW::CHASSIS::__Anonymous__::EgomotionTimestampStruct, BMW::CHASSIS::__Anonymous__::EgoVelocityStruct, 
// BMW::CHASSIS::__Anonymous__::EgoAccelerationStruct, BMW::CHASSIS::__Anonymous__::EgoRotationRatesStruct, BMW::CHASSIS::__Anonymous__::SteeringAngleStruct, BMW::CHASSIS::__Anonymous__::VehicleBodyOrientationToLaneSurfaceStruct, 
// BMW::CHASSIS::__Anonymous__::VehicleBodyOrientationToHorizonStruct, BMW::CHASSIS::__Anonymous__::EgoOdometryStruct>::Listener’ {aka ‘std::function<void(const short unsigned int&, const short unsigned int&, 
// const unsigned int&, const unsigned int&, const BMW::CHASSIS::__Anonymous__::EgomotionTimestampStruct&, const BMW::CHASSIS::__Anonymous__::EgoVelocityStruct&, const BMW::CHASSIS::__Anonymous__::EgoAccelerationStruct&, 
// const BMW::CHASSIS::__Anonymous__::EgoRotationRatesStruct&, const BMW::CHASSIS::__Anonymous__::SteeringAngleStruct&, const BMW::CHASSIS::__Anonymous__::VehicleBodyOrientationToLaneSurfaceStruct&, 
// const BMW::CHASSIS::__Anonymous__::VehicleBodyOrientationToHorizonStruct&, const BMW::CHASSIS::__Anonymous__::EgoOdometryStruct&)>’}

// note:   initializing argument 1 of ‘CommonAPI::Event<Arguments_>::Subscription CommonAPI::Event<Arguments_>::subscribe(CommonAPI::Event<Arguments_>::Listener, CommonAPI::Event<Arguments_>::ErrorListener) 
// [with Arguments_ = {short unsigned int, short unsigned int, unsigned int, unsigned int, BMW::CHASSIS::__Anonymous__::EgomotionTimestampStruct, BMW::CHASSIS::__Anonymous__::EgoVelocityStruct, 
// BMW::CHASSIS::__Anonymous__::EgoAccelerationStruct, BMW::CHASSIS::__Anonymous__::EgoRotationRatesStruct, BMW::CHASSIS::__Anonymous__::SteeringAngleStruct, BMW::CHASSIS::__Anonymous__::VehicleBodyOrientationToLaneSurfaceStruct, 
// BMW::CHASSIS::__Anonymous__::VehicleBodyOrientationToHorizonStruct, BMW::CHASSIS::__Anonymous__::EgoOdometryStruct}; CommonAPI::Event<Arguments_>::Subscription = unsigned int; 
// CommonAPI::Event<Arguments_>::Listener = std::function<void(const short unsigned int&, const short unsigned int&, const unsigned int&, const unsigned int&, const BMW::CHASSIS::__Anonymous__::EgomotionTimestampStruct&, 
// const BMW::CHASSIS::__Anonymous__::EgoVelocityStruct&, const BMW::CHASSIS::__Anonymous__::EgoAccelerationStruct&, const BMW::CHASSIS::__Anonymous__::EgoRotationRatesStruct&, const BMW::CHASSIS::__Anonymous__::SteeringAngleStruct&, 
// const BMW::CHASSIS::__Anonymous__::VehicleBodyOrientationToLaneSurfaceStruct&, const BMW::CHASSIS::__Anonymous__::VehicleBodyOrientationToHorizonStruct&, const BMW::CHASSIS::__Anonymous__::EgoOdometryStruct&)>; 
// CommonAPI::Event<Arguments_>::ErrorListener = std::function<void(CommonAPI::CallStatus)>]’
//   105 | typename Event<Arguments_...>::Subscription Event<Arguments_...>::subscribe(Listener listener, ErrorListener errorListener) {

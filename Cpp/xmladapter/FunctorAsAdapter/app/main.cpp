#include "speed.hpp"
#include "persistance.hpp"

int main(){
    SpeedProcessOutpuData speed_out_data{
        {{123.0f,66.341234f,SpeedUnit::kmh},{SpeedUnit::kmh, 86u, 79u, SpeedUnit::mph},true},
        {8,6,123,456723,{67.783987,SpeedUnit::kmh}}};
    
    PersistanceData<SpeedProcessOutpuData> persistancedata(&speed_out_data);

    //write the buffer to a file
    persistancedata.WriteDataToFile("sample.txt", sizeof(speed_out_data));


   SpeedProcessOutpuData *speed_out_data2 = persistancedata.ReadDataFromFile("sample.txt", sizeof(speed_out_data));
    //memcpy(speed_out_data2,persistancedata.ReadDataFromFile("sample.txt", sizeof(speed_out_data)),sizeof(SpeedProcessOutpuData));
    // = reinterpret_cast<SpeedProcessOutpuData*>(Readbuffer);
    
    std::cout << "sizeof(speed_out_data) = " << sizeof(speed_out_data) << std::endl;
    std::cout << "sizeof(SpeedProcessOutpuData) = " << sizeof(SpeedProcessOutpuData) << std::endl;
    //std::cout << "sizeof(buffer) = " << sizeof(Readbuffer) << std::endl;

    std::cout << speed_out_data2->displayed_speed.speed_analog.Kmh_Analog << " ";
    std::cout << speed_out_data2->displayed_speed.speed_analog.Mph_Analog<< " ";
    std::cout << speed_out_data2->displayed_speed.speed_analog.Unit_Analog_Speed << std::endl;
    std::cout << speed_out_data2->displayed_speed.speed_numeric.Unit_First_Speed<< " ";
    std::cout << speed_out_data2->displayed_speed.speed_numeric.Kmh_Digital<< " ";
    std::cout << speed_out_data2->displayed_speed.speed_numeric.Mph_Digital<< " ";
    std::cout << speed_out_data2->displayed_speed.speed_numeric.Unit_Second_Speed << std::endl;
    std::cout << boolalpha << speed_out_data2->displayed_speed.emergency_operation << std::endl;

    std::cout << speed_out_data2->dynamic_display_driver_assistance.crc_length << " ";
    std::cout << speed_out_data2->dynamic_display_driver_assistance.crc_counter << " ";
    std::cout << speed_out_data2->dynamic_display_driver_assistance.crc_id << " ";
    std::cout << speed_out_data2->dynamic_display_driver_assistance.crc << " ";
    std::cout << speed_out_data2->dynamic_display_driver_assistance.display_speed.value << " ";
    std::cout << speed_out_data2->dynamic_display_driver_assistance.display_speed.unit << std::endl;
    return 0;
}

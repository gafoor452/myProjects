#include <iostream>
#include <fstream>
#include <string.h>
#include "speed.hpp"

using namespace std;

void WriteDataToFile(const char* path, uint8_t* buffer, uint8_t length){
    ofstream filetoWrite;
    filetoWrite.open(path, ios::out);
    for(uint8_t i=0; i<length;i++)
        filetoWrite<<buffer[i];
    filetoWrite.close();
}


void ReadDataToFile(const char* path, uint8_t* buffer, uint8_t length){
    ifstream filetoRead;
    filetoRead.open(path,ios::in);
    for(uint8_t i=0; i<length;i++)
        filetoRead>>buffer[i];
    filetoRead.close();
}


int main(){
    SpeedProcessOutpuData speed_out_data{
        {{123.0f,66.34f,SpeedUnit::kmh},{SpeedUnit::kmh, 86u, 79u, SpeedUnit::mph},true},
        {8,6,123,456723,{67.78,SpeedUnit::kmh}}};
    //know the lenght of the object

    //create a byte array with the objects length

    //do intrepret cast to a uint8 buffer
    uint8_t *Writebuffer= reinterpret_cast<uint8_t*>(&speed_out_data);

    //write the buffer to a file
    WriteDataToFile("sample.txt", Writebuffer, sizeof(speed_out_data));


    uint8_t *Readbuffer = new uint8_t [sizeof(uint8_t)*sizeof(speed_out_data)];
    ReadDataToFile("sample.txt", Readbuffer, sizeof(speed_out_data));
    SpeedProcessOutpuData *speed_out_data2 = reinterpret_cast<SpeedProcessOutpuData*>(Readbuffer);
    
    std::cout << "sizeof(speed_out_data) = " << sizeof(speed_out_data) << std::endl;
    std::cout << "sizeof(SpeedProcessOutpuData) = " << sizeof(SpeedProcessOutpuData) << std::endl;
    std::cout << "sizeof(buffer) = " << sizeof(Readbuffer) << std::endl;

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

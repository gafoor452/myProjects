#include <optional>
#include <type_traits>
#include <iostream>
enum SpeedUnit{
    kmh = 0,
    mph = 1,
    off = 2
};

struct SpeedAnalog{
    float Kmh_Analog; //4
    float Mph_Analog; //4
    SpeedUnit Unit_Analog_Speed; //1
}; //9

struct SpeedNumeric{
    SpeedUnit Unit_First_Speed; //1
    uint16_t Kmh_Digital;   //2
    uint16_t Mph_Digital;   //2
    SpeedUnit Unit_Second_Speed; //1
}; //6

struct DisplayedSpeed {
  SpeedAnalog speed_analog; //9
  SpeedNumeric speed_numeric; //6
  bool emergency_operation; //1
}; //16

struct DisplaySpeed{
    float value; //4
    SpeedUnit unit; //1
}; //5

struct DynamicDisplayDriverAssistance {
  uint16_t crc_length; //2
  uint16_t crc_counter; //2
  uint32_t crc_id;  //4
  uint32_t crc;   //4
  DisplaySpeed display_speed; //5
}; //17

struct SpeedProcessOutpuData {
  DisplayedSpeed displayed_speed; //16
 // std::optional<DynamicDisplayDriverAssistance> dynamic_display_driver_assistance; //17
  DynamicDisplayDriverAssistance dynamic_display_driver_assistance;
}; //33

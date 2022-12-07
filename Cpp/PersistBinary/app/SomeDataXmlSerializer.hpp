#ifndef SOMEDATAXMLSERIALIZER_HPP
#define SOMEDATAXMLSERIALIZER_HPP

#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

#include "Serializer.hpp"
#include "SomeDataOutput.hpp"
#include "pugixml.hpp"

class SomeDataXmlSerializer : public Serializer<SomeDataOutput, pugi::xml_document> {
 public:
  auto Serialize(SomeDataOutput& entity) -> pugi::xml_document override;
  auto Desserialize(pugi::xml_document& payload) -> SomeDataOutput override;
};

template <typename T>
const char* ValueToConstChar(T value) {
  std::ostringstream oss;
  // std::wstringstream oss;
  if (typeid(value).name() == std::string("d") || typeid(value).name() == std::string("f"))
    oss << std::setprecision(6) << std::fixed << value;
  else
    oss << value;
  //   oss.write(reinterpret_cast<const char*>(&value), sizeof(T));
  //   if (typeid(value).name() == std::string("d") || typeid(value).name() == std::string("f"))
  //     oss.write(reinterpret_cast<const char*>(&value), sizeof(T));

  //   else
  //     oss << value;
  return oss.str().data();
}

auto SomeDataXmlSerializer::Serialize(SomeDataOutput& entity) -> pugi::xml_document {
  pugi::xml_document doc{};
  pugi::xml_node function_name = doc.append_child("Speed");

  pugi::xml_node first_speed = function_name.append_child("FirstSpeed");
  pugi::xml_node first_speed_analog = first_speed.append_child("AnalogSpeed");
  pugi::xml_node first_speed_digital = first_speed.append_child("DigitalSpeed");
  pugi::xml_node second_speed = function_name.append_child("SecondSpeed");
  pugi::xml_node second_speed_analog = second_speed.append_child("AnalogSpeed");
  pugi::xml_node second_speed_digital = second_speed.append_child("DigitalSpeed");

  first_speed_analog.append_child(pugi::node_pcdata).set_value(ValueToConstChar(entity.first_speed_.analog_));
  first_speed_digital.append_child(pugi::node_pcdata).set_value(ValueToConstChar(entity.first_speed_.digital_));
  second_speed_analog.append_child(pugi::node_pcdata).set_value(ValueToConstChar(entity.second_speed_.analog_));
  second_speed_digital.append_child(pugi::node_pcdata).set_value(ValueToConstChar(entity.second_speed_.digital_));

  //   doc.print(std::cout);
  return doc;
}

auto SomeDataXmlSerializer::Desserialize(pugi::xml_document& payload) -> SomeDataOutput {
  SomeDataOutput entity{};
  pugi::xml_node function_name = payload.child("Speed");
  pugi::xml_node first_speed = function_name.child("FirstSpeed");
  pugi::xml_node first_speed_analog = first_speed.child("AnalogSpeed");
  pugi::xml_node first_speed_digital = first_speed.child("DigitalSpeed");
  pugi::xml_node second_speed = function_name.child("SecondSpeed");
  pugi::xml_node second_speed_analog = second_speed.child("AnalogSpeed");
  pugi::xml_node second_speed_digital = second_speed.child("DigitalSpeed");

  // float* ptr = reinterpret_cast<float*>(const_cast<char*>(first_speed_analog.child_value()));
  entity.first_speed_.analog_ = static_cast<float>(atof(first_speed_analog.child_value()));
  entity.first_speed_.digital_ = atoi(first_speed_digital.child_value());
  entity.second_speed_.analog_ = static_cast<float>(atof(second_speed_analog.child_value()));
  entity.second_speed_.digital_ = atoi(second_speed_digital.child_value());

  //   entity.first_speed_.analog_ = *reinterpret_cast<float*>(const_cast<char*>(first_speed_analog.child_value()));
  //   entity.first_speed_.digital_ =
  //   *reinterpret_cast<uint16_t*>(const_cast<char*>(first_speed_digital.child_value())); entity.second_speed_.analog_
  //   = *reinterpret_cast<float*>(const_cast<char*>(second_speed_analog.child_value())); entity.second_speed_.digital_
  //   = *reinterpret_cast<uint16_t*>(const_cast<char*>(second_speed_digital.child_value()));
  return entity;
}
#endif
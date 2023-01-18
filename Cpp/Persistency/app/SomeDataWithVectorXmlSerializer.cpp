#include "SomeDataWithVectorXmlSerializer.hpp"

#include <vector>

#include "base64/Decoded.hpp"

auto SomeDataWithVectorXmlSerializer::Serialize(SomeDataWithVectorOutput& entity) -> pugi::xml_document {
  pugi::xml_document doc{};
  pugi::xml_node root_node = doc.append_child("FunctionData");
  pugi::xml_node speeds_node = root_node.append_child("Speeds");
  pugi::xml_node sum_node = root_node.append_child("Sum");

  for (auto speed : entity.speeds_) {
    pugi::xml_node speed_node = speeds_node.append_child("Speed");
    FillSpeedNode(speed_node, speed);
  }
  sum_node.append_child(pugi::node_pcdata).set_value(Encoder::Encode(entity.sum_).c_str());
  std::string comment{"Sum = " + ConvertToString(entity.sum_)};
  root_node.append_child(pugi::node_comment).set_value(comment.c_str());
  return doc;
}

auto SomeDataWithVectorXmlSerializer::Desserialize(pugi::xml_document& payload) -> SomeDataWithVectorOutput {
  SomeDataWithVectorOutput entity{};
  pugi::xml_node root_node = payload.child("FunctionData");
  pugi::xml_node speeds_node = root_node.child("Speeds");
  pugi::xml_node sum_node = root_node.child("Sum");

  for (auto speed = speeds_node.begin(); speed != speeds_node.end(); ++speed) {
    Decoded analog = Decoder::Decode(speed->child("Analog").child_value());
    uint16_t digital = ConvertToType<uint16_t>(speed->child("Digital").child_value());
    SomeDataWithVectorOutput::Speed speed_entity{digital, static_cast<float>(analog)};
    entity.speeds_.emplace_back(speed_entity);
  }
  entity.sum_ = static_cast<float>(Decoder::Decode(sum_node.child_value()));
  return entity;
}

void SomeDataWithVectorXmlSerializer::FillSpeedNode(pugi::xml_node& node, SomeDataWithVectorOutput::Speed& speed) {
  pugi::xml_node digital_node = node.append_child("Digital");

  pugi::xml_node analog_node = node.append_child("Analog");
  std::string comment{"Analog = " + ConvertToString(speed.analog_)};
  node.append_child(pugi::node_comment).set_value(comment.c_str());

  digital_node.append_child(pugi::node_pcdata).set_value(ConvertToString(speed.digital_).c_str());
  analog_node.append_child(pugi::node_pcdata).set_value(Encoder::Encode(speed.analog_).c_str());
}

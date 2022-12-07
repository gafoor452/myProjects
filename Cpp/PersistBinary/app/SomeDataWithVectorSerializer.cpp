#include "SomeDataWithVectorSerializer.hpp"

#include <algorithm>
#include <sstream>
#include <vector>
auto SomeDataWithVectorSerializer::Serialize(SomeDataWithVectorOutput& entity) -> BinaryPayload {
  size_t main_entity_size = sizeof(float);
  size_t vector_size = entity.speeds_.size();
  size_t speed_entity_size = sizeof(SomeDataWithVectorOutput::Speed);
  std::ostringstream oss{};
  size_t index = 0;
  oss << "\n#SomeData\n";
  oss << "speeds_.sum: " << entity.sum << std::endl;
  for (SomeDataWithVectorOutput::Speed speed : entity.speeds_) {
    oss << "speeds_.[" << index << "].digital_: " << speed.digital_ << std::endl;
    oss << "speeds_.[" << index << "].analog_: " << speed.analog_ << std::endl;
    index++;
  }

  uint32_t total_size = main_entity_size + (vector_size * speed_entity_size) + sizeof(oss);
  BinaryPayload binary_payload{total_size};
  binary_payload << entity.sum;
  binary_payload << vector_size;

  for (SomeDataWithVectorOutput::Speed speed : entity.speeds_) {
    binary_payload << speed.analog_;
    binary_payload << speed.digital_;
  }
  binary_payload.Add(oss.str());
  return binary_payload;
}

auto SomeDataWithVectorSerializer::Desserialize(BinaryPayload& payload) -> SomeDataWithVectorOutput {
  SomeDataWithVectorOutput entity{};
  size_t vector_size;
  payload >> entity.sum;
  payload >> vector_size;
  for (size_t ix = 0; ix < vector_size; ++ix) {
    SomeDataWithVectorOutput::Speed speed{};
    payload >> speed.analog_;
    payload >> speed.digital_;
    entity.speeds_.push_back(speed);
  }
  return entity;
}

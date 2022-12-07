#include "SomeDataBinarySerializer.hpp"

#include <algorithm>
#include <sstream>
#include <vector>

#include "BinaryPayload.hpp"

auto SomeDataBinarySerializer::Serialize(SomeDataOutput& entity) -> BinaryPayload {
  std::ostringstream oss{};
  size_t entity_size = sizeof(SomeDataOutput);
  char* entity_bytes = reinterpret_cast<char*>(&entity);
  oss << "\n#SomeData\n";
  oss << "#first_speed_.digital_: " << entity.first_speed_.digital_ << std::endl;
  oss << "#first_speed_.analog_: " << entity.first_speed_.analog_ << std::endl;
  oss << "#second_speed_.digital_: " << entity.second_speed_.digital_ << std::endl;
  oss << "#second_speed_.analog_: " << entity.second_speed_.analog_ << std::endl;
  size_t comment_size = oss.str().length() * sizeof(char);
  size_t total_size = entity_size + comment_size;
  BinaryPayload binary_payload{entity_size, total_size};
  binary_payload.Add(entity_bytes, entity_bytes + entity_size);
  binary_payload.Add(oss.str());
  return binary_payload;
}

auto SomeDataBinarySerializer::Desserialize(BinaryPayload& payload) -> SomeDataOutput {
  SomeDataOutput* entity_ptr = reinterpret_cast<SomeDataOutput*>(payload.Data());
  return *entity_ptr;
}
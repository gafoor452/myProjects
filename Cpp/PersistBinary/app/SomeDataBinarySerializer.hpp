#ifndef SOMEDATABINARYSERIALIZER_HPP
#define SOMEDATABINARYSERIALIZER_HPP

#include "Serializer.hpp"
#include "SomeDataOutput.hpp"

class BinaryPayload;

class SomeDataBinarySerializer : public Serializer<SomeDataOutput, BinaryPayload> {
 public:
  auto Serialize(SomeDataOutput& entity) -> BinaryPayload override;
  auto Desserialize(BinaryPayload& payload) -> SomeDataOutput override;
};

#endif  // SOMEDATABINARYSERIALIZER_HPP
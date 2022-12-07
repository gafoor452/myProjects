#ifndef SOMEDATAWITHVECTORSERIALIZER_HPP
#define SOMEDATAWITHVECTORSERIALIZER_HPP

#include "BinaryPayload.hpp"
#include "Serializer.hpp"
#include "SomeDataWithVectorOutput.hpp"

class SomeDataWithVectorSerializer : public Serializer<SomeDataWithVectorOutput, BinaryPayload> {
 public:
  auto Serialize(SomeDataWithVectorOutput& entity) -> BinaryPayload override;
  auto Desserialize(BinaryPayload& payload) -> SomeDataWithVectorOutput override;
};



#endif  // SOMEDATAWITHVECTORSERIALIZER_HPP
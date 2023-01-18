#ifndef __SOMEDATAWITHVECTORXMLSERIALIZERHPP__
#define __SOMEDATAWITHVECTORXMLSERIALIZERHPP__

#include <string>

#include "SomeDataWithVectorOutput.hpp"
#include "base64/Decoder.hpp"
#include "base64/Encoder.hpp"
#include "persistency/Serializer.hpp"
#include "pugixml/pugixml.hpp"
#include "utility/Convert.hpp"

class SomeDataWithVectorXmlSerializer : public Serializer<SomeDataWithVectorOutput, pugi::xml_document> {
 public:
  auto Serialize(SomeDataWithVectorOutput& entity) -> pugi::xml_document override;
  auto Desserialize(pugi::xml_document& payload) -> SomeDataWithVectorOutput override;

 private:
  void FillSpeedNode(pugi::xml_node& node, SomeDataWithVectorOutput::Speed& speed);
};

#endif  // SomeDataWithVectorXmlSerializer.hpp
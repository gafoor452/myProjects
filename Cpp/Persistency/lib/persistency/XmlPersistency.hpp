#ifndef XMLPERSISTENCY_HPP
#define XMLPERSISTENCY_HPP

#include "Persistency.hpp"
#include "pugixml/pugixml.hpp"

template <typename Entity, typename EntitySerializer>
class XmlPersistency : public Persistency<Entity> {
 public:
  XmlPersistency(std::string&& file_path);
  void Save(Entity& entity) override;
  auto Load() -> Entity override;

 private:
  EntitySerializer entity_serializer{};
};

template <typename Entity, typename EntitySerializer>
XmlPersistency<Entity, EntitySerializer>::XmlPersistency(std::string&& file_path)
    : Persistency<Entity>(std::move(file_path)) {}

template <typename Entity, typename EntitySerializer>
void XmlPersistency<Entity, EntitySerializer>::Save(Entity& entity) {
  pugi::xml_document doc{entity_serializer.Serialize(entity)};
  doc.save_file(Persistency<Entity>::file_path_.data());
}

template <typename Entity, typename EntitySerializer>
auto XmlPersistency<Entity, EntitySerializer>::Load() -> Entity {
  pugi::xml_document doc{};
  doc.load_file(Persistency<Entity>::file_path_.data());
  Entity entity = entity_serializer.Desserialize(doc);
  return entity;
}
#endif
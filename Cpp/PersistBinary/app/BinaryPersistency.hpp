#ifndef BINARYPERSISTENCY_HPP
#define BINARYPERSISTENCY_HPP

#include <cstdint>
#include <fstream>
#include <string>

#include "BinaryPayload.hpp"
#include "Persistency.hpp"

template <typename Entity, typename EntitySerializer>
class BinaryPersistency : public Persistency<Entity> {
 public:
  BinaryPersistency(std::string&& file_path);
  void Save(Entity& entity) override;
  auto Load() -> Entity override;

 private:
  EntitySerializer entity_serializer{};
};

template <typename Entity, typename EntitySerializer>
BinaryPersistency<Entity, EntitySerializer>::BinaryPersistency(std::string&& file_path)
    : Persistency<Entity>(std::move(file_path)) {}

template <typename Entity, typename EntitySerializer>
void BinaryPersistency<Entity, EntitySerializer>::Save(Entity& entity) {
  BinaryPayload binary_payload = entity_serializer.Serialize(entity);
  std::ofstream ofs{Persistency<Entity>::file_path_, std::ios_base::binary};
  size_t useful_size = binary_payload.UsefulSize();
  ofs.write(reinterpret_cast<char*>(&useful_size), sizeof(size_t));
  ofs.write(binary_payload.Data(), binary_payload.TotalSize());
  ofs.flush();
  ofs.close();
};

template <typename Entity, typename EntitySerializer>
auto BinaryPersistency<Entity, EntitySerializer>::Load() -> Entity {
  std::ifstream ifs{Persistency<Entity>::file_path_, std::ios_base::binary};
  size_t useful_size;
  char* useful_size_ptr = reinterpret_cast<char*>(&useful_size);
  ifs.read(useful_size_ptr, sizeof(size_t));
  BinaryPayload binary_payload{useful_size};

  ifs.read(binary_payload.Data(), useful_size);
  ifs.close();
  Entity entity = entity_serializer.Desserialize(binary_payload);
  Entity copy_entity{entity};
  return (copy_entity);
};

#endif  // BINARYPERSISTENCY_HPP
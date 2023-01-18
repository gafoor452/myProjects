#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
template <typename Entity, typename Payload>
class Serializer {
 public:
  virtual auto Serialize(Entity& entity) -> Payload = 0;
  virtual auto Desserialize(Payload& payload) -> Entity = 0;
};
#endif  // SERIALIZER_HPP
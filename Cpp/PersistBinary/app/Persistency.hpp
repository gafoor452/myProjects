#ifndef PERSISTENCY_HPP
#define PERSISTENCY_HPP
#include <string>

template <typename Entity>
class Persistency {
 public:
  Persistency(std::string&& file_path);
  virtual ~Persistency() = default;
  virtual void Save(Entity& entity) = 0;
  virtual auto Load() -> Entity = 0;

 protected:
  std::string file_path_;
  
};

template <typename Entity>
Persistency<Entity>::Persistency(std::string&& file_path) : file_path_{file_path} {};

#endif  // PERSISTENCY_HPP
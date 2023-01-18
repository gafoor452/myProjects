#ifndef DECODED_HPP
#define DECODED_HPP
#include <stddef.h>

#include "Types.hpp"

class Decoded {
 public:
  Decoded(size_t size);
  ~Decoded();
  byte* Get();

  template <typename T>
  operator T();

 private:
  byte* decoded_;
  size_t size_;
};

template <typename T>
Decoded::operator T() {
  T* ptr = reinterpret_cast<T*>(decoded_);
  return *ptr;
}

inline byte* Decoded::Get() { return decoded_; }

#endif  // DECODED_HPP
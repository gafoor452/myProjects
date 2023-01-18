#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <stddef.h>

#include <array>
#include <iomanip>
#include <string>
#include <type_traits>

#include "Config.hpp"
#include "Types.hpp"

class Encoder {
 public:
  template <typename T>
  static std::string Encode(T&& value);

 private:
  static std::string EncodeBytes(byte* bytes, size_t size);
  static void Encode3Bytes(std::string& result, byte byteA, byte byteB, byte byteC);
  static constexpr Encoding64Table encoding_{get_base64_encoding_table()};
};

template <typename T>
std::string Encoder::Encode(T&& value) {
  size_t size = sizeof(value);
  byte* bytes = reinterpret_cast<byte*>(&value);
  return EncodeBytes(bytes, size);
}

#endif  // ENCODER_HPP
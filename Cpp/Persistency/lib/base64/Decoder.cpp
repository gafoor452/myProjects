#include "Decoder.hpp"

#include <stddef.h>
Decoded Decoder::Decode(std::string&& encoded) {
  size_t decoded_length = (encoded.length() / 4) * 3;
  Decoded decoded{decoded_length};
  byte* ptr = decoded.Get();
  for (size_t ix = 0; ix < encoded.length(); ix += 4) {
    ByteBuffer tmp{0x00};
    tmp = (decoding_[encoded.at(ix)] << 18) | (decoding_[encoded.at(ix + 1)] << 12) |
          (decoding_[encoded.at(ix + 2)] << 6) | (decoding_[encoded.at(ix + 3)]);
    *ptr = (tmp >> 16) & 0xFF;
    ++ptr;
    *ptr = (tmp >> 8) & 0xFF;
    ++ptr;
    *ptr = tmp & 0xFF;
    ++ptr;
  }
  return decoded;
}

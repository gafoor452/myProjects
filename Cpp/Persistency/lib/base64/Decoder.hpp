#ifndef DECODER_HPP
#define DECODER_HPP

#include <array>
#include <string>

#include "Config.hpp"
#include "Decoded.hpp"
#include "Types.hpp"

class Decoder {
 public:
  static Decoded Decode(std::string&& encoded);

 private:
  static constexpr Decoding64Table decoding_{get_base64_decoding_table()};
};

#endif  // DECODER_HPP
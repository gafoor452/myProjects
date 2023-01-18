#include "Encoder.hpp"

std::string Encoder::EncodeBytes(byte* bytes, size_t size) {
  size_t remaining = size % 3;
  std::string::size_type result_size = ((size - remaining) / 3) * 4 + (remaining > 0 ? 4 : 0);
  std::string result{};
  result.reserve(result_size);
  byte* ptr = bytes;
  for (size_t ix = 0; ix < (size - remaining); ix += 3) {
    byte byteA = *(ptr++);
    byte byteB = *(ptr++);
    byte byteC = *(ptr++);
    Encode3Bytes(result, byteA, byteB, byteC);
  }
  if (remaining == 2) {
    byte byteA = *(ptr++);
    byte byteB = *(ptr++);
    byte byteC = 0x00;
    Encode3Bytes(result, byteA, byteB, byteC);
  } else if (remaining == 1) {
    byte byteA = *(ptr++);
    byte byteB = 0x00;
    byte byteC = 0x00;
    Encode3Bytes(result, byteA, byteB, byteC);
  }
  return result;
}

inline void Encoder::Encode3Bytes(std::string& result, byte byteA, byte byteB, byte byteC) {
  ByteBuffer bytes_together = 0x00;
  bytes_together |= (byteA << 16) & 0xFF0000;
  bytes_together |= (byteB << 8) & 0xFF00;
  bytes_together |= byteC & 0xFF;
  result += encoding_[bytes_together >> 18 & 0b00111111];
  result += encoding_[bytes_together >> 12 & 0b00111111];
  result += encoding_[bytes_together >> 6 & 0b00111111];
  result += encoding_[bytes_together & 0b00111111];
}

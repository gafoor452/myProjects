#ifndef BINARYPAYLOAD_HPP
#define BINARYPAYLOAD_HPP
#include <algorithm>
#include <cstddef>
#include <string>
class BinaryPayload {
 public:
  BinaryPayload(size_t useful_size);
  BinaryPayload(size_t useful_size, size_t total_size);
  ~BinaryPayload();
  template <typename T>
  BinaryPayload& operator<<(T data);
  template <typename T>
  BinaryPayload& operator>>(T& data);
  auto Data() -> char*;
  auto TotalSize() -> size_t const;
  auto UsefulSize() -> size_t const;
  template <typename SourceIt>
  void Add(SourceIt first_source, SourceIt last_source);
  void Add(std::string str);

 private:
  char* payload_;
  char* read_offset_;
  char* write_offset_;
  size_t useful_size_;
  size_t total_size_;
};

inline auto BinaryPayload::Data() -> char* { return payload_; }

inline auto BinaryPayload::TotalSize() -> size_t const { return total_size_; }

inline auto BinaryPayload::UsefulSize() -> size_t const { return useful_size_; }

template <typename T>
BinaryPayload& BinaryPayload::operator<<(T data) {
  size_t data_size = sizeof(T);
  char* bytes_ptr = reinterpret_cast<char*>(&data);
  for (size_t ix = 0; ix < data_size; ++ix) {
    *write_offset_ = *bytes_ptr;
    ++bytes_ptr;
    ++write_offset_;
  }
  return *this;
}

template <typename T>
BinaryPayload& BinaryPayload::operator>>(T& data) {
  T* payload_data = reinterpret_cast<T*>(read_offset_);
  data = *payload_data;
  read_offset_ += sizeof(T);
  return *this;
}

template <typename SourceIt>
void BinaryPayload::Add(SourceIt first_source, SourceIt last_source) {
  write_offset_ = std::copy(first_source, last_source, write_offset_);
}

#endif  // BINARYPAYLOAD_HPP

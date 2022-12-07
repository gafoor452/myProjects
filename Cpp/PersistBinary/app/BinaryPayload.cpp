#include "BinaryPayload.hpp"

#include <string.h>

#include <vector>

BinaryPayload::BinaryPayload(size_t useful_size) : useful_size_{useful_size}, total_size_{useful_size} {
  payload_ = new char[useful_size];
  read_offset_ = payload_;
  write_offset_ = payload_;
}

BinaryPayload::BinaryPayload(size_t useful_size, size_t total_size)
    : useful_size_{useful_size}, total_size_{total_size} {
  payload_ = new char[total_size];
  read_offset_ = payload_;
  write_offset_ = payload_;
}

BinaryPayload::~BinaryPayload() { delete[] payload_; }

void BinaryPayload::Add(std::string str) {
  size_t length = str.length();
  std::vector<char> aux = {str.begin(), str.end()};
  char* bytes = &aux[0];
  write_offset_ = std::copy(bytes, bytes + length, write_offset_);
}
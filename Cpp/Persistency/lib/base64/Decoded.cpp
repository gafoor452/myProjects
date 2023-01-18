#include "Decoded.hpp"

Decoded::Decoded(size_t size) : size_{size} { decoded_ = new byte[size]; }

Decoded::~Decoded() { delete[] decoded_; }

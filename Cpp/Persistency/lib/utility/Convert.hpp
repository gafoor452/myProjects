#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <sstream>
#include <string>

template <typename T>
std::string ConvertToString(T value) {
  std::ostringstream oss{};
  oss << value;
  return oss.str();
}

template <typename T>
T ConvertToType(const char* value) {
  std::istringstream iss{value};
  T data{};
  iss >> data;
  return data;
}

#endif  // CONVERT_HPP
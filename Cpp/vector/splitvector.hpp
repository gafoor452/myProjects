#include <iostream>
#include <type_traits>
#include <vector>

// template <typename T,typename... Ts>
// void split_data(std::vector<T> &data, Ts &&... args) {
//   //using U = std::decay_t<decltype(args)>;
//   //std::size_t const typelen{sizeof(U)};
//   std::size_t const typelen  = sizeof...(Ts);
//   std::cout << "size -- " << typelen << "-----"<<std::endl;
//   for (std::size_t i = 0; i < typelen; i++) {
//     (data.emplace_back(std::forward<T>(args)), ...);
//     std::cout<< "adding element" << args<< std::endl;
//   }
// }

uint8_t constexpr kBitsInByte{8U};
uint8_t constexpr kEightBitMask{0xFFU};

template <typename T>
auto constexpr GetByteIndex(size_t i) -> size_t {
  if constexpr (true) {
    return (sizeof(T) - (i + 1));
  }
  return i;
}

template <typename T>
auto constexpr GetByte(T &&value, size_t i) -> uint8_t {
  return static_cast<uint8_t>((value >> (GetByteIndex<T>(i) * kBitsInByte)) & kEightBitMask);
}

template <typename T, typename... Ts>
void split_data2(std::vector<T> &data, Ts... args) {
  auto split=[&data](auto &&val) {
    using U = std::decay_t<decltype(val)>;
    std::size_t typelen = sizeof(U);
    for (std::size_t i = 0; i < typelen; i++) {
      data.push_back(std::forward<T>(GetByte(val, i)));
      //std::cout << "adding element" << std::hex<< val << std::endl;
    }
  };
  (split((data,std::forward<Ts>(args))),...);
}
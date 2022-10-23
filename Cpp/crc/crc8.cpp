#include<iostream>
#include<array>


typedef unsigned char uint8_t;

auto Crc8Lut(uint8_t const polynom) -> std::array<uint8_t, 256U> {
  std::array<uint8_t, 256U> tlut{0U};
  uint8_t table_index{0U};
  for (auto &entry : tlut) {
    entry = table_index;
    ++table_index;
    for (uint8_t i{0U}; i < 8; ++i) {
      uint8_t const current_bit{static_cast<uint8_t>(entry & (1U << 7U))};
      entry = static_cast<uint8_t>(entry << 1U);
      if (current_bit > 0U) {
        entry = static_cast<uint8_t>(entry ^ polynom);
      }
    }
  }
  return tlut;
}

int main(){
    std::array<uint8_t, 256> kTable{Crc8Lut(0x1D)};
    unsigned int j =0;
    for(uint8_t i:kTable)
    {
        std::cout<< "kTable["<<std::dec << j<<"] = " <<std::hex<<static_cast<unsigned int>(i) <<" "<< std::endl;
        j++;
        }
    return 0;
}
#include<iostream>

template<typename TYPE>
TYPE RefelctionOfBits(TYPE number) {
  TYPE reflected_number = 0U;
  unsigned int max_bits = (sizeof(TYPE)*8) -1;
  for (int i = 0; i <= max_bits; i++) {
    if (number & (1 << i)) {
      reflected_number |= (1 << (max_bits - i));
    }
  }
  return reflected_number;
}

int main(void){
std::cout<< std::hex << RefelctionOfBits(static_cast<unsigned int>(0xF4ACFB13U)) << std::endl;
}
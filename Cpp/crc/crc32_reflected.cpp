#include<iostream>
#include<array>


typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

auto Crc32Lut(uint32_t const polynom) -> std::array<uint32_t, 256U>;

uint32_t constexpr kCrc32Polynomreflect{0xEDB88320};
uint32_t constexpr kCrc32Polynom{0x4C11DB7U};

std::array<uint32_t, 256U> crcTable{0};// = new uint32_t[256];
std::array<uint32_t, 256> kTable{Crc32Lut(kCrc32Polynomreflect)};

/*The below one is working fine*/
auto Crc32Lut(uint32_t const polynom) -> std::array<uint32_t, 256U> {
  std::array<uint32_t, 256U> tlut{0};
  uint32_t table_index{0U}; //todo - make from 32bit to 8bit as 256 is fine
  for (auto &entry : tlut) {
    entry = table_index;
    ++table_index;
    uint32_t currentByte = static_cast<uint32_t>(entry);
    for (uint8_t i{8U}; i > 0; --i) {
      if((currentByte & 1U)){
          currentByte = currentByte >> 1;
          currentByte = currentByte ^ polynom;
      }
      else{
        currentByte = currentByte >> 1;
      }
    }
    entry = currentByte;
  }
  return tlut;
}

uint32_t Compute_CRC32(uint8_t bytes[])
{
    uint32_t crc = 0xffffffff;
    for(uint8_t b = 0;b<1;b++)
    {
        /* XOR-in next input byte into MSB of crc and get this MSB, that's our new intermediate divident */
        uint8_t pos = (uint8_t)((crc ^ (bytes[b] << 24)) >> 24);
        /* Shift out the MSB used for division per lookuptable and XOR with the remainder */
        crc = (uint32_t)((crc << 8) ^ (uint32_t)(kTable[pos]));
    }

    return (crc^0xffffffff);
}

int main(){
    
    unsigned int j =0;
    std::array<uint32_t, 256> kTable{Crc32Lut(kCrc32Polynomreflect)};
    for(unsigned int i=0;i<256;i++)
    {
     // std::cout<< "crcTable["<<std::dec << i<<"] = " <<std::hex<< crcTable[i]<<"    ";
      std::cout<< "kTable["<<std::dec << i<<"] = " <<std::hex<<kTable[i] <<" "<< std::endl;
      j++;
    }
    // uint8_t data=0x01U;
    // std::cout<< std::hex<< Compute_CRC32(&data);
    return 0;
}
#include<iostream>

typedef unsigned char uint8_t;

enum class EndianValue : uint8_t { Little = 1U, Big = 2U };
uint8_t constexpr kEightBitMask{0xFFU};
uint8_t constexpr kBitsInByte{8U};

static uint8_t const kMsb = 0x01U;
static uint8_t const kLsb = 0x02U;
static uint16_t const kFirstLastByte = 0x0102U;

class MachineEndian {
 private:
  // This is the dark magic, it uses the first byte and based on that, the
  // endianess is determined. This could all be removed in C++20.
  // NOLINTNEXTLINE
  static constexpr uint8_t kMagic{(uint8_t const &)kFirstLastByte};

 public:
  static constexpr bool kLittle{kMagic == kLsb};
  static constexpr bool kBig{kMagic == kMsb};
  static_assert(kLittle || kBig, "Cannot determine endianness!");
  MachineEndian() = delete;
  static constexpr auto Value() -> EndianValue;
};

template <EndianValue Endianess, typename T>
auto constexpr GetByteIndex(size_t i) -> size_t {
    size_t len;
  if constexpr (Endianess == EndianValue::Little) {
    len = (sizeof(T) - (i + 1));
  }
  else{
    len = i;
  }
  std::cout<<"  place = " << len << "   ";
  return len;
}

template <EndianValue Endianess, typename T>
void GetByte(T value, size_t i){
  uint8_t databyte;
  std::cout << "value:" << value << "    i:" << i ;
  databyte = static_cast<uint8_t>((value >> (GetByteIndex<Endianess, T>(i) * kBitsInByte)) & kEightBitMask);
  std::cout<< (databyte+48) <<std::endl;
}

template <EndianValue Endianess, typename T>
void ComputeCrcOverIntegral(T &&in) {
  using U = std::decay_t<decltype(in)>;
  std::size_t const typelen{sizeof(U)};
  std::cout<<typelen<<std::endl;
  for (std::size_t i = 0; i < typelen; i++) {
    GetByte<Endianess>(in, i);
  }
}

int main(){

    unsigned int a = 0x01020304;
    ComputeCrcOverIntegral<EndianValue::Little>(a);
    ComputeCrcOverIntegral<EndianValue::Big>(a);
    return 0;
}
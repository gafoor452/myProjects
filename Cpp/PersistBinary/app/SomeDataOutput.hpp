#ifndef SOMEDATAOUTPUT_HPP
#define SOMEDATAOUTPUT_HPP

#include <cstdint>

struct SomeDataOutput {
  struct Speed {
    Speed() = default;

    uint16_t digital_;
    float analog_;
  };

  Speed first_speed_{};  // 1child has 2 children digital_,analog
  Speed second_speed_{};
};

#endif  // SOMEDATAOUTPUT_HPP
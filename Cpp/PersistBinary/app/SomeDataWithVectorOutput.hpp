#ifndef SOMEDATAWITHVECTOROUTPUT_HPP
#define SOMEDATAWITHVECTOROUTPUT_HPP

#include <cstdint>
#include <vector>

struct SomeDataWithVectorOutput {
  struct Speed {
    Speed() = default;

    uint16_t digital_;
    float analog_;
  };

  std::vector<Speed> speeds_;
  float sum;
};

#endif  // SOMEDATAWITHVECTOROUTPUT_HPP
#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>

void Benchmark1(int const repeat_times) {
  std::chrono::high_resolution_clock::time_point start =
      std::chrono::high_resolution_clock::now();
  for (int ix = 0; ix < repeat_times; ++ix) {
    // TODO: place here the code to benchmark test
  }
  std::chrono::high_resolution_clock::time_point end =
      std::chrono::high_resolution_clock::now();
  std::chrono::microseconds duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Benchmark took: " << duration.count() << " microseconds.\n";
}

void Benchmark2(int const repeat_times) {
  std::chrono::high_resolution_clock::time_point start =
      std::chrono::high_resolution_clock::now();
  for (int ix = 0; ix < repeat_times; ++ix) {
    // TODO: place here another code to benchmark test
  }
  std::chrono::high_resolution_clock::time_point end =
      std::chrono::high_resolution_clock::now();
  std::chrono::microseconds duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Benchmark took: " << duration.count() << " microseconds.\n";
}

int main(int argc, char *argv[]) {
  int repeat_times = 1;
  int type = 1;
  if (argc >= 2) {
    std::stringstream ss{argv[1]};
    ss >> repeat_times;
  }
  if (argc == 3) {
    std::stringstream ss{argv[2]};
    ss >> type;
  }

  std::cout << "Testing benchmark type " << type << " for " << repeat_times
            << " times.\n";
  if (type == 1) {
    Benchmark1(repeat_times);
  } else if (type == 2) {
    Benchmark2(repeat_times);
  } else {
    std::cout << "Unknown benchmark test type.\n";
  }
}

#include "BinaryPersistency.hpp"
#include "SomeDataBinarySerializer.hpp"
#include "SomeDataOutput.hpp"
#include "SomeDataWithVectorOutput.hpp"
#include "SomeDataWithVectorSerializer.hpp"
#include "SomeDataXmlSerializer.hpp"
#include "XmlPersistency.hpp"
#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
SomeDataOutput some_data{{50, 50.543201f}, {27, 27.5f}};
inline void binary_save() {
  BinaryPersistency<SomeDataOutput, SomeDataBinarySerializer> persistency{
      "./persisted"};
  // SomeDataOutput some_data{};
  // some_data.first_speed_.analog_ = 50.543201f;
  // some_data.first_speed_.digital_ = 50;
  // some_data.second_speed_.analog_ = 27.5;
  // some_data.second_speed_.digital_ = 27;
  persistency.Save(some_data);
}

inline void binary_load() {
  BinaryPersistency<SomeDataOutput, SomeDataBinarySerializer> persistency{
      "./persisted"};
  SomeDataOutput some_data_loaded{persistency.Load()};
}

inline void xml_save() {
  XmlPersistency<SomeDataOutput, SomeDataXmlSerializer> xml_persistecny{
      "./persisted.xml"};
  // SomeDataOutput some_data{};
  // some_data.first_speed_.analog_ = 50.543201f;
  // some_data.first_speed_.digital_ = 50;
  // some_data.second_speed_.analog_ = 27.5f;
  // some_data.second_speed_.digital_ = 27;
  xml_persistecny.Save(some_data);
}

inline void xml_load() {
  XmlPersistency<SomeDataOutput, SomeDataXmlSerializer> xml_persistecny_load{
      "./persisted.xml"};
  SomeDataOutput some_data_loaded{xml_persistecny_load.Load()};
}
void Benchmark1(int const repeat_times, std::string load_save) {
  if (load_save == "save") {
    std::chrono::high_resolution_clock::time_point start =
        std::chrono::high_resolution_clock::now();

    for (int ix = 0; ix < repeat_times; ++ix) {
      // TODO: place here the code to benchmark test
      binary_save();
    }
    std::chrono::high_resolution_clock::time_point end =
        std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Benchmark took: " << duration.count() << " microseconds.\n";
  } else if (load_save == "load") {
    std::chrono::high_resolution_clock::time_point start =
        std::chrono::high_resolution_clock::now();

    for (int ix = 0; ix < repeat_times; ++ix) {
      // TODO: place here the code to benchmark test
      binary_load();
    }
    std::chrono::high_resolution_clock::time_point end =
        std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Benchmark took: " << duration.count() << " microseconds.\n";
  }
}

void Benchmark2(int const repeat_times, std::string load_save) {
  if (load_save == "save") {
    std::chrono::high_resolution_clock::time_point start =
        std::chrono::high_resolution_clock::now();
    for (int ix = 0; ix < repeat_times; ++ix) {
      // TODO: place here another code to benchmark test
      xml_save();
    }
    std::chrono::high_resolution_clock::time_point end =
        std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Benchmark took: " << duration.count() << " microseconds.\n";
  } else if (load_save == "load") {
    std::chrono::high_resolution_clock::time_point start =
        std::chrono::high_resolution_clock::now();
    for (int ix = 0; ix < repeat_times; ++ix) {
      // TODO: place here another code to benchmark test
      xml_load();
    }
    std::chrono::high_resolution_clock::time_point end =
        std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Benchmark took: " << duration.count() << " microseconds.\n";
  }
}

int main(int argc, char *argv[]) {
  int repeat_times = 1;
  int type = 1;
  std::string load_save = "save";
  if (argc >= 2) {
    std::stringstream ss{argv[1]};
    ss >> repeat_times;
  }
  // if (argc == 3) {
  //   std::stringstream ss{argv[2]};
  //   ss >> type;
  // }

  if (argc == 4) {
    std::stringstream ss1{argv[2]};
    ss1 >> type;
    std::stringstream ss2{argv[3]};
    ss2 >> load_save;
  }

  std::cout << "Testing benchmark type " << type << " -- " << load_save
            << " for " << repeat_times << " times.\n";
  if (type == 1) {
    Benchmark1(repeat_times, load_save);
  } else if (type == 2) {
    Benchmark2(repeat_times, load_save);
  } else {
    std::cout << "Unknown benchmark test type.\n";
  }
}


#include <iostream>

#include "BinaryPersistency.hpp"
#include "SomeDataBinarySerializer.hpp"
#include "SomeDataOutput.hpp"
#include "SomeDataWithVectorOutput.hpp"
#include "SomeDataWithVectorSerializer.hpp"
#include "SomeDataXmlSerializer.hpp"
#include "XmlPersistency.hpp"

void trial1() {
  BinaryPersistency<SomeDataOutput, SomeDataBinarySerializer> persistency{"./persisted"};
  SomeDataOutput some_data{};
  some_data.first_speed_.analog_ = 50.543201f;
  some_data.first_speed_.digital_ = 50;
  some_data.second_speed_.analog_ = 27.5;
  some_data.second_speed_.digital_ = 27;
  persistency.Save(some_data);

  SomeDataOutput some_data_loaded{persistency.Load()};
  std::cout << "Binary Persistancy data" << std::endl;
  std::cout << "some_data_loaded.first_speed_.analog_: " << std::setprecision(6) << std::fixed
            << some_data_loaded.first_speed_.analog_ << std::endl;
  std::cout << "some_data_loaded.first_speed_.digital_: " << some_data_loaded.first_speed_.digital_ << std::endl;
  std::cout << "some_data_loaded.second_speed_.analog_: " << std::setprecision(6) << std::fixed
            << some_data_loaded.second_speed_.analog_ << std::endl;
  std::cout << "some_data_loaded.second_speed_.digital_: " << some_data_loaded.second_speed_.digital_ << std::endl;
}

void trial2() {
  BinaryPersistency<SomeDataWithVectorOutput, SomeDataWithVectorSerializer> persistency{"./persisted_with_vector"};
  SomeDataWithVectorOutput some_data{};
  some_data.speeds_.push_back(SomeDataWithVectorOutput::Speed{10, 10.5});
  some_data.speeds_.push_back(SomeDataWithVectorOutput::Speed{20, 20.4});
  some_data.speeds_.push_back(SomeDataWithVectorOutput::Speed{30, 30.3});
  some_data.speeds_.push_back(SomeDataWithVectorOutput::Speed{40, 40.2});
  some_data.sum = 12.654321;
  persistency.Save(some_data);
  SomeDataWithVectorOutput some_data_loaded{persistency.Load()};
  std::cout << "some_data_loaded.sum: " << some_data_loaded.sum << std::endl;
  int ix = 0;
  for (SomeDataWithVectorOutput::Speed speed : some_data_loaded.speeds_) {
    std::cout << "some_data_loaded.speeds_.digital(" << ix << "): " << speed.digital_ << std::endl;
    std::cout << "some_data_loaded.speeds_.analog(" << ix << "): " << speed.analog_ << std::endl;
    ++ix;
  }
}

void trial3() {
  BinaryPersistency<SomeDataOutput, SomeDataBinarySerializer> persistency{"./persisted"};
  SomeDataOutput some_data_loaded{persistency.Load()};
  std::cout << "some_data_loaded.first_speed_.analog_: " << some_data_loaded.first_speed_.analog_ << std::endl;
  std::cout << "some_data_loaded.first_speed_.digital_: " << some_data_loaded.first_speed_.digital_ << std::endl;
  std::cout << "some_data_loaded.second_speed_.analog_: " << some_data_loaded.second_speed_.analog_ << std::endl;
  std::cout << "some_data_loaded.second_speed_.digital_: " << some_data_loaded.second_speed_.digital_ << std::endl;
}

void trial4() {
  BinaryPersistency<SomeDataWithVectorOutput, SomeDataWithVectorSerializer> persistency{"./persisted_with_vector"};
  SomeDataWithVectorOutput some_data_loaded{persistency.Load()};
  std::cout << "some_data_loaded.sum: " << some_data_loaded.sum << std::endl;
  int ix = 0;
  for (SomeDataWithVectorOutput::Speed speed : some_data_loaded.speeds_) {
    std::cout << "some_data_loaded.speeds_.analog(" << ix << "): " << speed.analog_ << std::endl;
    std::cout << "some_data_loaded.speeds_.digital(" << ix << "): " << speed.digital_ << std::endl;
    ++ix;
  }
}

void xml_trial1() {
  XmlPersistency<SomeDataOutput, SomeDataXmlSerializer> xml_persistecny{"./persisted.xml"};
  SomeDataOutput some_data{};
  some_data.first_speed_.analog_ = 50.543201f;
  [[maybe_unused]] float *ptr4 = &some_data.first_speed_.analog_;
  some_data.first_speed_.digital_ = 50;

  some_data.second_speed_.analog_ = 27.5f;
  [[maybe_unused]] float *ptr3 = &some_data.second_speed_.analog_;
  some_data.second_speed_.digital_ = 27;
  xml_persistecny.Save(some_data);

  XmlPersistency<SomeDataOutput, SomeDataXmlSerializer> xml_persistecny_load{"./persisted.xml"};
  SomeDataOutput some_data_loaded{xml_persistecny_load.Load()};
  [[maybe_unused]] float *ptr1 = &some_data_loaded.first_speed_.analog_;
  [[maybe_unused]] float *ptr2 = &some_data_loaded.second_speed_.analog_;
  std::cout << "XML Persistancy data" << std::endl;
  std::cout << "some_data_loaded.first_speed_.analog_: " << std::setprecision(6)
            << some_data_loaded.first_speed_.analog_ << std::endl;
  // std::cout << "some_data_loaded.first_speed_.analog_: " << some_data_loaded.first_speed_.analog_ << std::endl;
  std::cout << "some_data_loaded.first_speed_.digital_: " << some_data_loaded.first_speed_.digital_ << std::endl;
  std::cout << "some_data_loaded.second_speed_.analog_: " << std::setprecision(6)
            << some_data_loaded.second_speed_.analog_ << std::endl;
  // std::cout << "some_data_loaded.second_speed_.analog_: " << some_data_loaded.second_speed_.analog_ << std::endl;
  std::cout << "some_data_loaded.second_speed_.digital_: " << some_data_loaded.second_speed_.digital_ << std::endl;
}

int main() {
  trial1();
  // trial2();
  // trial3();
  // trial4();
  xml_trial1();
  std::cout << std::flush;
}

#include <iostream>

#include "SomeDataWithVectorOutput.hpp"
#include "SomeDataWithVectorXmlSerializer.hpp"
#include "persistency/XmlPersistency.hpp"

void XmlSaveExample(std::string &&path) {
  XmlPersistency<SomeDataWithVectorOutput, SomeDataWithVectorXmlSerializer> xml_persistecny{std::move(path)};
  SomeDataWithVectorOutput some_data{};
  some_data.speeds_.push_back(SomeDataWithVectorOutput::Speed{10, 10.5});
  some_data.speeds_.push_back(SomeDataWithVectorOutput::Speed{20, 20.4});
  some_data.speeds_.push_back(SomeDataWithVectorOutput::Speed{30, 30.3});
  some_data.speeds_.push_back(SomeDataWithVectorOutput::Speed{40, 40.2});
  some_data.sum_ = 12.654321f;
  xml_persistecny.Save(some_data);
}

void XmlLoadExample(std::string &&path) {
  XmlPersistency<SomeDataWithVectorOutput, SomeDataWithVectorXmlSerializer> xml_persistecny{std::move(path)};
  SomeDataWithVectorOutput some_data{xml_persistecny.Load()};
  int ix = 0;
  for (SomeDataWithVectorOutput::Speed speed : some_data.speeds_) {
    std::cout << "some_data.speeds_.analog(" << ix << "): " << speed.analog_ << std::endl;
    std::cout << "some_data.speeds_.digital(" << ix << "): " << speed.digital_ << std::endl;
    ++ix;
  }

  std::cout << "some_data.sum_ = " << std::setprecision(8) << some_data.sum_ << std::endl;
}

int main() {
  XmlSaveExample("./out/Data.xml");
  XmlLoadExample("./out/Data.xml");
  std::cout << std::flush;
}
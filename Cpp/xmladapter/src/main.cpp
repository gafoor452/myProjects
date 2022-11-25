#include "./../pugixml_src/pugixml.hpp"
#include <iostream>
#include <string.h>
#include <type_traits>

template <typename FuncType>
class persistantdata : public pugi::xml_document, pugi::xml_parse_result {

public:
#if 0
  FuncType *ReadData(std::string file_location) {
    result = doc.load_file(
        "/home/gafoor/myWork/myProjects/Cpp/xmladapter/src/sample.xml");
    // char *cp = new char[255];
    //     fun_var_.signal1 =
    //     doc.child("function").child("digitalspeed1").text().as_uint();
    //     fun_var_.signal2 =
    //     doc.child("function").child("digitalspeed2").text().as_float();
    node = doc.child("function").first_child();
    int i = 0;
    for (pugi::xml_node_iterator it = node.begin(); it != node.end(); ++it) {
      // std::cout << it->attribute("type").value() << std::endl;
      if (strcmp(it->attribute("type").value(), "int")) {
        // auto child_node = it->value();
        std::cout << it->child_value() << " ";
        // << " gafoor" << i << std::endl;
        // pugi::xml_attribute ait = it->attribute("type");

        // std::cout << ait.value() << " gafoor" << i << std::endl;
      } else {
        std::cout << "Not found ";
      }
      std::cout << it->attribute("type").value() << " " << i << std::endl;
      i++;
    }
    return &fun_var_;
  }
#endif

#if 1
  FuncType *GetDataByLocation(const char *file_location) {
    // FuncType fun_var_;
    result = doc.load_file(file_location);
    pugi::xml_node node = doc.child("function");
    for (pugi::xml_node child : node.children()) {
      // std::cout << child.name() << " " << child.child_value() << std::endl;
      // fun_var_.signal1 = child.child_value();
    }
    return &fun_var_;
  }

  void WriteDataByLocation(const char *file_location, const FuncType &fun) {
    std::cout << std::boolalpha << std::is_class_v<FuncType> << std::endl;
  }
#endif

protected:
private:
  FuncType fun_var_;
  pugi::xml_document doc;
  pugi::xml_parse_result result;
  // TODO - write function to get the type and
  // void provideSignalType()
};

struct function {
  int signal1;
  float signal2;
};

int main(void) {
  function Speed{123, 45.7};
  persistantdata<function> pd;
  pd.WriteDataByLocation(
      "/home/gafoor/myWork/myProjects/Cpp/xmladapter/src/sample3.xml", &Speed);
  //   memcpy(&Speed,
  //          pd.GetDataByLocation(
  //              "/home/gafoor/myWork/myProjects/Cpp/xmladapter/src/sample.xml"),
  //          sizeof(function));

  return 0;
}

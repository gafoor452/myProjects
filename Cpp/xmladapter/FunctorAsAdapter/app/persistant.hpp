#include "pugixml.hpp"

class persistantdata : public pugi::xml_document, pugi::xml_parse_result {

public:

//   FuncType *GetDataByLocation(const char *file_location) {
//     // FuncType fun_var_;
//     result = doc.load_file(file_location);
//     pugi::xml_node node = doc.child("function");
//     for (pugi::xml_node child : node.children()) {
//       // std::cout << child.name() << " " << child.child_value() << std::endl;
//       // fun_var_.signal1 = child.child_value();
//     }
//     return &fun_var_;
//   }

  protected:
private:
  //FuncType fun_var_;
  pugi::xml_document doc;
  pugi::xml_parse_result result;
  // TODO - write function to get the type and
  // void provideSignalType()
};
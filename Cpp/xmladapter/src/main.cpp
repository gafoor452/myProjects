#include <iostream>
#include <string.h>
#include "./../pugixml_src/pugixml.hpp"

template<typename FuncType> 
class persistantdata : public pugi::xml_document, pugi::xml_parse_result{
   
    public:
    FuncType* ReadData(std::string file_location){
        result = doc.load_file("/home/gafoor/myWork/myProjects/Cpp/xmladapter/src/sample.xml");
        char *cp = new char[255];
       fun_var_.signal1 = doc.child("function").child("digitalspeed1").text().as_uint();
       fun_var_.signal2 = doc.child("function").child("digitalspeed2").text().as_float();
       return &fun_var_;
    }

    protected:

    private:
    FuncType fun_var_; 
    pugi::xml_document doc;
    pugi::xml_parse_result result;
};

struct function{
    int signal1;
    float signal2;
};

int main(void) {
    function Speed{0,0};
    persistantdata<function> pd;
    memcpy(&Speed,pd.ReadData("/home/gafoor/myWork/myProjects/Cpp/xmladapter/src/sample.xml"),sizeof(function));
    std::cout<<Speed.signal1<<"   " <<Speed.signal2<<std::endl;
    return 0;
}

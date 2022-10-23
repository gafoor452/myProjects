#include<iostream>
#include<variant>
#include<string>

class Number{
    private:
    std::variant<std::string, uint8_t> value;

    public:
    virtual void setnumber(std::variant<std::string, uint8_t> val){
        value = val;
    } 
    virtual auto getnumber() -> std::variant<std::string, uint8_t> {return value;};
};

class STRNUM: Number{
    public:
    void setnumber(std::string val){
        Number::setnumber(value);
    }
    auto getnumber() -> std::string{
        return std::get<std::string>(Number::getnumber());
    }
};
class INTNUM: Number{
    public:
    void setnumber(uint8_t val){
        Number::setnumber(value);
    }
    auto getnumber() -> uint8_t {
        return std::get<uint8_t>(Number::getnumber());
    }
};
int main(){

    return 0;
}
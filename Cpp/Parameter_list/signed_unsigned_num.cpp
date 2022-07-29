#include<iostream>
#include<typeinfo>
#include<typeindex>
#include <variant>
#include <vector>
using namespace std;

template < typename... Ts>
void func(Ts... args){
    std::vector<std::variant<short int,unsigned short int, float, int>> data;
  (data.emplace_back(std::forward<Ts>(args)), ...);
  //for(auto i: data)
    //cout<<i<<endl;
  //cout<<typeid(i).name()<<endl;
  //cout<< i.type().name() << endl; 
}
/*
template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    //std::cout << value << std::endl;
    std::cout << typeid(value).name() << std::endl;
    (void) std::initializer_list<T>{([&args] {
        //std::cout << args << std::endl;
        std::cout << typeid(args).name() << std::endl;
        std::vector<std::variant<uint8_t, uint16_t, uint32_t, uint64_t>> data1;
        if(typeid(args).name() == typeid(short int).name())
            {
                //convert to unsigned
                unsigned short int a = args;
                data1.emplace_back(a);
            }
    }(), value)...};
}*/
/*
template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    //std::cout << value << std::endl;
    std::cout << typeid(value).name() << std::endl;
    std::vector<std::variant<uint8_t, uint16_t, uint32_t, uint64_t>> data1;
    (void) std::initializer_list<T>{([&args, &data1] {
        //std::cout << args << std::endl;
        std::cout << typeid(args).name() << std::endl;
        if(typeid(args).name() == typeid(short int).name())
            {
                //convert to unsigned
                unsigned short int a = args;
                data1.emplace_back(a);
            }
            else{unsigned short int a = args;
                data1.emplace_back(a);
                //data1.emplace_back(args);
                //data1.emplace_back(std::forward<Ts>(args));
                //(data1.emplace_back(std::forward<Ts>(args)), ...);
            }
    }(), value)...};

    //     < n << endl;
    cout<<"end"<<endl;
}*/
/*
template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    //std::cout << value << std::endl;
    std::cout << typeid(value).name() << std::endl;
    std::vector<std::variant<short int,unsigned short int, float, int>> data1;
    //std::initializer_list<T> &data2;
        //std::cout << args << std::endl;
        std::cout << typeid(args).name() << std::endl;
        if(typeid(args).name() == typeid(short int).name())
            {
                //convert to unsigned
                unsigned short int a = args;
                data1.emplace_back(a);
            }
            else{unsigned short int a = args;
                data1.emplace_back(a);
                //data1.emplace_back(args);
                //data1.emplace_back(std::forward<Ts>(args));
                //(data1.emplace_back(std::forward<Ts>(args)), ...);
            }
    

    //     < n << endl;
    cout<<"end"<<endl;
}*/

// auto check_args(std::variant<uint8_t,int8_t,int16_t, uint16_t, uint32_t, uint64_t> num)
// {

// }
template <typename...Ts>
void check_args(Ts... args){
    std::vector<std::variant<short int,unsigned short int, float, int>> data;
    if constexpr((std::is_signed_v<decltype<Ts>>(args), ...)){
        std::cout<<"yes\n";
    }
    else{
        std::cout<<"no\n";
    }
    //(data.emplace_back(std::forward<Ts>(args)), ...);
}
int main()
{
    short int a = -24;
    unsigned short int b = 6;
    short int c = -98;
    //b = a;
   // c = b;
    // cout<<"short int = "<<typeid(short int).name() <<endl;
    // cout<<"unsigned short int = "<<typeid(unsigned short int).name()<<endl;
    // cout<<"int = "<<typeid(int).name() <<endl;
    // cout<<"a = "<<a <<endl;
    // cout<<"b = "<<b <<endl;
    // cout<<"c = "<<c <<endl;
    // if(typeid(a)==typeid(short int))
    // {
    //     unsigned short int b;
    //     b = static_cast<unsigned short int>(a);
    //     cout<<"b = "<<b <<endl;
    // }
    //func(a,b,c);
    check_args(a,b,c);
    return 0;
}
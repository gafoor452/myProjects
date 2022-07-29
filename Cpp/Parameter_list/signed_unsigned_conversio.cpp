#include<iostream>
#include<typeinfo>
#include<typeindex>
#include<variant>
#include<vector>
#include<type_traits>

//void converttounsigned(std::variant<signed char,unsigned char,short int,unsigned short int, float, int> const arg)
// void converttounsigned(auto const arg)
// {
//     // if (typeid(arg).name() == typeid(signed char).name()){
//     //         unsigned char data = static_cast<unsigned char>(arg);
//     //       }else if (typeid(arg).name() == typeid(signed short int).name()){
//     //         unsigned short int data = static_cast<unsigned short int>(arg);
//     //       }else if (typeid(arg).name() == typeid(int32_t).name()){
//     //         uint32_t data = static_cast<uint32_t>(arg);
//     //       }else if (typeid(arg).name() == typeid(int64_t).name()){
//     //         uint64_t data = static_cast<uint64_t>(arg);
//     //       }
//     //       else{
//     //         auto data = arg;
//     //       }
//     if(std::is_signed_v()
//     cout << data << endl;
// }

template< typename T >
using make_unsigned_t = typename std::make_unsigned<T>::type   
;

template< typename T>
void checksign(T arg)
{
    std::cout << std::boolalpha;
    std::cout<<std::is_signed<T>::value;
    if(std::is_signed<T>::value){
        make_unsigned_t<T> data;
        data = arg;
        std::cout<< data <<std::endl;
        //return data;
    }
    //return arg;
}
int main(void){
    short int a = -24;
    unsigned short int b = 6;
    short int c = -98;
    checksign(a);
    checksign(b);
    // converttounsigned(a);
    // converttounsigned(b);
    // converttounsigned(c);
    return 0;
}
#include<iostream>
#include<string.h>

template <typename... Args>
struct Impl;

template <typename First, typename... Args>
struct Impl<First, Args...>
{
  static std::string name()
  {
    return std::string(typeid(First).name()) + " " + Impl<Args...>::name();
  }
};

template <>
struct Impl<>
{
  static std::string name()
  {
    return "";
  }
};

template <typename... Args>
std::string type_name()
{
    return Impl<Args...>::name();
}

int main()
{
  //std::cout << type_name<short int,unsigned short int, unsigned int, int, bool, char, unsigned char, double>() << std::endl; // "i b c d"
  short int a = -24;
    unsigned short int b = 6;
    short int c = -98;
    std::cout << type_name<a,b,c>() <<std::endl;
  return 0;
}
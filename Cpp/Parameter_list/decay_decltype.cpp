#include<iostream>
#include<vector>

template <typename T>
auto Gettype(T &&in){
    //using U = std::decay_t<decltype(in)>;  // Which datatype it can give
  std::size_t const typelen{sizeof(decltype(in))};
  std::cout << typelen << std::endl;
  return typelen;
}

int main(void)
{
    std::vector<unsigned char> v={1,2,3,4,5};
    unsigned short int size = Gettype(v);

    std::cout << size << std::endl;
}
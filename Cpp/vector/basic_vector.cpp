#include"splitvector.hpp"

int main(void)
{
    short int x = 0x1265;
    short int y = 0x1854;
    char z = 0x04;
    // std::vector<short int>v1{x,y};

    // for(short int i:v1){
    //     std::cout<< i << std::endl;
    // }

    // std::vector<char>v1{&x,&y};

    // for(const char *i:v1){
    //     std::cout<< *i << std::endl;
    // }


    // char z = 0x57;
    // short int a = 9348;
    // std::vector<short int>v1{x,y,z,a};

    // for(short int i:v1){
    //     std::cout<< i << std::endl;
    // }

    
    
    // std::vector<short int>v1{x,y};
    // std::vector<short int>v2{v1};

    // for(short int i:v1){
    //     std::cout<< i << std::endl;
    // }
    // for(short int i:v2){
    //     std::cout<< i << std::endl;
    // }
    const std::vector<char> vec1;
    // std::cout<<"sizeof(x):" << sizeof(x)<<std::endl;
    // std::cout<<"sizeof(y):" << sizeof(y)<<std::endl;
    // std::cout<<"sizeof(z):" << sizeof(z)<<std::endl;
    split_data2(vec1,x,y,z);
    for(short int i:vec1){
        std::cout<< std::hex<< i << std::endl;
    }
    return 0;
}
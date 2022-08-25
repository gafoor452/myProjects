#include<iostream>
#include<vector>

int main(void)
{
    short int x = 0x1265;
    short int y = 0x1454;

    std::vector<short int> v1{x,y};

    for(short int i:v1){
        std::cout<< i << std::endl;
    }
    return 0;
}
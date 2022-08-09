#include<iostream>

template<unsigned int T = static_cast<unsigned int>(5U), typename U>
auto product(U x){
    return T*x;
}

template<unsigned char s, typename T,typename U>
void calculation(char s,T x,U y){
    
    switch (s)
    {
    case '+': auto sum = x+y;
            std::cout<<"sum: "<<sum<<std::endl;
        break;
    case '-': auto diff = x-y;
            std::cout<<"diff: "<<diff<<std::endl;
        break;
    default:
        break;
    }
}

int main()
{
    std::cout << product(4) << std::endl;
    std::cout << (product<9>(9))<< std::endl;
    std::cout << product<10>(4.5) << std::endl;
    calculation('+',3,4);
}
#include<iostream>
template <int n>
class num{
    public:
    template<typename T>
    int square(T y);
    // int square(T y){
    //     y = n+y;
    //     std::cout<<y<<std::endl;
    //     return n*n;
    // }
};
template <int n>
template<typename T>
int num<n>::square(T y){
    y = n+y;
    std::cout<<y<<std::endl;
    return n*n;
}
int main(){
    num<5> n1;
    std::cout<<n1.square<int>(0)<<std::endl;
return 0;
}
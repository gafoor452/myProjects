#include<iostream>
using namespace std;
class Foo{
    int num;
    public:
    Foo(int n) : num{n}{};
    int getFoo(){ return num;}
};

void FunFoo(Foo f){
    cout<<f.getFoo()<<endl;
}
class FooBar{
    int num;
    public:
    explicit FooBar(int n) : num{n}{};
    int getFooBar(){ return num;}
};

void FunFooBar(FooBar f){
    cout<<f.getFooBar()<<endl;
}
int main(){
    FunFoo(3);
    FunFoo(5.5);
    // FunFooBar(5);
    FunFooBar(FooBar(3)); //As the constructor is explicit we need to call the constructor in the function
    FunFooBar(FooBar(5.5));  
    
}
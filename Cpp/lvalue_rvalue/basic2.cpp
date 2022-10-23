#include<iostream>

using namespace std;

void lvaluefunc(int& x){
    cout<< x << endl;
}

void rvaluefunc(int&& x){
    cout<< x << endl;
}

void lrvaluefunc(const int& x){
    cout<< x << endl;
}

int main(void){
    int x=3;
    //int *y = &x; //here x is lvalue and &x(address of x) is a rvalue and it is a litteral
    //int *z = &333; //error: lvalue required as unary ‘&’ operand
    lvaluefunc(x);
    rvaluefunc(10);
    lrvaluefunc(x);
    lrvaluefunc(10);
    return 0;
}
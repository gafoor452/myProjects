#include<iostream>

using namespace std;

void func(int val){
cout<< val << endl;
}

int main(void){
    int x=3;//here x is lvalue - as it has memory to store the variable
            //3 is rvalue - as it is not stored in the memory, 3 it is a literal 
    //3 = x; // error: lvalue required as left operand of assignment
    func(x);
    func(5);

    int &xref = x; //xref is reference of x
    func(xref);

    //int &lref = 10; //error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    const int &lref = 10;
    //lref++; error: increment of read-only reference ‘lref’
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int var = 10;
    int &ref = var;
    int *ptr = &var;
    cout<< var <<'\t' <<ref <<'\t' << ptr << endl;
    cout<< &var <<'\t' <<&ref <<'\t' << ptr <<'\t' << &ptr << endl;
    delete[] ptr;
    return 0;
}
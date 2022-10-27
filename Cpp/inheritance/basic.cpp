#include<iostream>
using namespace std;

class Base{
    private:
    int value;
    public:
    Base(int val): value{val}{cout << "In Base Class Constructor"<<endl;}
    ~Base(){cout<<"In Base Class Destructor"<<endl;}
    void setValue(int val){
        value=val;
    }
    int getValue(void) const {return value;}
};

//In Dervied class private members of base class are not used
class Dervied: public Base{
    public:
    //Here in the constructor of basecalss with argument shall be used
    Dervied(int val = 0):Base(val){cout << "In Derived Class Constructor"<<endl;}
    ~Dervied(){cout<<"In Dervied Class Destructor"<<endl;}
};

int main(void){
    //Base base_obj(10);
    Dervied dobj;
    dobj.setValue(19);
    cout<<dobj.getValue()<<endl;
    return 0;
}
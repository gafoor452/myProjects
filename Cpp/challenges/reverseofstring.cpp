#include<iostream>
using namespace std;
int main(){
    char a[10]="madam";
    int size=0;
    for(int i=0;a[i]!='\0';i++)
    size++;
    cout<<size<<endl;
    for(int i=0;i<size/2;i++){
        char t = a[i];
        a[i] = a[size-1-i];
        a[size-1-i] = t;
    }
    cout<<a<<endl;
    return 0;
}
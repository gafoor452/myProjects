#include<iostream>
#include<thread>

using namespace std;
void threadFun1(void){
    cout<< "In thread1 func" <<endl;
}
void threadFun2(void){
    cout<< "In thread2 func" <<endl;
}
int main(){
    std::thread t1(threadFun1);
    std::thread t2(threadFun2);
    t1.join();
    t2.join();
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    std::vector<int> vec{1,2,3,4,5};
    int sum = 0;
    bool b = std::all_of(vec.cbegin(),vec.cend(),[&sum](int x){sum = x+0;});
    cout << sum << endl;
    // if (std::all_of(v.cbegin(), v.cend(), [](int i){ return i % 2 == 0; })) {
    //     std::cout << "All numbers are even\n";
    // }else{
    //     std::cout << "All numbers arenot even\n";
    // }
    return 0;
}
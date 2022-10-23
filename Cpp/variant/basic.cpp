#include<iostream>
#include<variant>

enum ENDAY{DAY0=0,DAY1,DAY2,DAY3};
enum ENWEEK{SUN=0,MON,TUE,WED};

int main(void){
    std::variant<ENDAY,ENWEEK> var;
    ENWEEK x;
    var = ENDAY::DAY1;
    x = std::visit([](auto&& arg){return static_cast<ENWEEK>(arg);}, var);
    return 0;
}
//find the largest anagram substring in a given string
//things learnt
//string - substring function, length function, 
//map - empty(), to get the max element.
//algorithm - std::max_element(), 
#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;
std::map<int,std::string> anagrammap;
void isanagram(const std::string& str){
    int mid = str.length()/2;
    for(int i=0;i<=mid;i++){
        if(str[mid-i]==str[mid+i])
            continue;
        else
            return;
    }
    std::pair<int,std::string> p1{str.length(),str};
    anagrammap.emplace(p1);
}

int main(void){
    std::string inputstring;
    getline(cin,inputstring);
    unsigned short len = inputstring.length();
    char refChar,sChar;
    for(int i=0;i<inputstring.length();i++){
        refChar = inputstring[i];
        for(int j=i+1;j<=inputstring.length();j++){
        if(refChar!=inputstring[j])
            continue;
        else{
            std::string substring;
            substring = inputstring.substr(i,j-i+1);
            isanagram(substring);
        }
        }
    }
    if(!anagrammap.empty()){
        auto max= std::max_element(anagrammap.begin(),anagrammap.end());
        cout<<max->second<<endl;
    }
    return 0;
}
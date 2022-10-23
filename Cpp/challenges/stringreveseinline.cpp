#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

void reverse(char* p){
    int length = 0;
    for(int i=0;p[i]!='\0';i++)
    length++;
    for(int i=0;i<length/2;i++){
        char t = p[i];
        p[i] = p[length-1-i];
        p[length-1-i] = t;
    }
}

int main()
{
    std::string sentence;
    getline(cin,sentence);
    char* charsent = new char [sentence.length()+1];
    std::strcpy(charsent,sentence.c_str());
    char *space = std::strtok(charsent," ");
    while(space!=0)
    {
        reverse(space);
        cout<<space<<"  ";
        space = std::strtok(NULL," ");
    }
    return 0;
}
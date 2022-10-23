#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using std::string;
using std::vector;

using namespace std;

string text = {"(65480,'v1','source'),(216579,'c3','capacitor'),(981328,'r2','resisotr')"};

string text1 = "0.542,3.333,3.120,9.000,4.200,3.000,1.750,4.000,0.364,3.400,2.667,3.423,2.211,4.950,2.111,0.250,0.150,13.143,0.852,2.444,4.765,1.091,4.545,0.455,6.000,2.793,0.038,3.286,2.909,17.500,2.444,0.391,72.000,2.368,4.455,1.857,19.000,3.600,3.042,3.167,4.625,1.840,2.000,1.158,3.278,3.909,1.000,4.333,2.500,5.538,2.929,20.000,3.550,0.778,2.500,2.667,3.095,3.103,10.200,2.353,3.429,3.480,3.667";



int main(int argc, char* argv[])
{
  string delimeter = "(";
  vector<float> numbers;
  //List<float> list = {};

  size_t pos = 0;
  while ((pos = text.find(delimeter)) != string::npos)
  {
    string subStr = text.substr(0, pos);
    std::cout<<subStr;
    // float value = std::stof(subStr);
    // numbers.push_back(value);
    // text.erase(0, delimeter.length());
  }

  for (float &num : numbers)
  {
    std::cout << num <<endl;
  }
}
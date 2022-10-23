#include<iostream>
#include<string>
#include<list>
#include<vector>

using namespace std;

class Component{
    unsigned int id;
    std::string name;
    std::string type;
};

class ValueofComponent{
    unsigned int value;
    std::string type;
};

vector<string> explode(const string& str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}

std::string get_str_between_two_str(const std::string &s,
        const char&start_delim,
        const char &stop_delim)
{
    unsigned first_delim_pos = s.find(start_delim);
    unsigned end_pos_of_first_delim = first_delim_pos + 1;
    unsigned last_delim_pos = s.find(stop_delim);
 
    return s.substr(end_pos_of_first_delim,
            last_delim_pos - end_pos_of_first_delim);
}
 


int main(void){
    std::string component_input_ = {"(65480,'v1','source'),(216579,'c3','capacitor'),(981328,'r2','resisotr')"};
    unsigned first = component_input_.find('(');
    unsigned last = component_input_.find(',');
    std::vector<char> vec;

    std::cout << first << endl;
    std::cout << last << endl;
    std::string extract_string;
    extract_string = get_str_between_two_str(component_input_, '(', ',');//std::endl;
    int number = stoi(extract_string);
    cout << number << endl;
    // for (size_t i = first+1; i < last; i++) {

    //     //vec.emplace_back(i);
    //     cout << "\"" << get_str_between_two_str() << "\"" << endl;
    // }

    //cout<<vec<<endl;

    // std::vector<std::string> result = explode(component_input_, '(');
    // for (size_t i = 0; i < result.size(); i++) {
    //     cout << "\"" << result[i] << "\"" << endl;
    // }
    // std::vector<std::string> result2 = explode(result[0], ',');
    // for (size_t i = 0; i < result.size(); i++) {
    //     cout << "\"" << result[i] << "\"" << endl;
    // }
    return 0;
}
#include <iostream>
#include <set>

int main() {
    // std::set Sets are a type of associative container in which each element has to be unique because 
    // the value of the element identifies it. The values are stored in a specific sorted order i.e. either ascending or descending
    // In the below example, there are few numbers repeated and not in the order. But set will remove duplicates and arrange them in ascending
    std::set<uint16_t> original_meesage_ids={6,2,6,7,8,8,3};
    original_meesage_ids.emplace(1);
    original_meesage_ids.emplace(9);
    original_meesage_ids.emplace(7);
    for(auto& str: original_meesage_ids)
  {
    std::cout << str << ' ';
  }

    return 0;
}
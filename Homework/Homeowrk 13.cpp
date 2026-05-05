#include <iostream>
#include <map>

int main() {

    //original maps
    std::map<int, int> numbers1_temp = {
    {1,1}, {2,2}, {3,3}, {4,4}, {5,5},
    {6,6}, {7,7}, {8,8}, {9,9}
};

std::map<int, int> numbers2 = {
    {1,10}, {2,20}, {3,30}, {4,40}, {5,50},
    {6,60}, {7,70}, {8,80}, {9,90}
};

//interlace map
std::map<int, std::pair<int, int>> numbers1;

// Iterators
auto it1 = numbers1_temp.begin();
auto it2 = numbers2.begin();

//more iteration with iterators
while (it1 != numbers1_temp.end() || it2 != numbers2.end()) 
{
if (it1 != numbers1_temp.end() && it2 != numbers2.end()) {
    numbers1[it1->first] = {it1->second, it2->second}; ++it1; ++it2;
}
else if (it1 != numbers1_temp.end()) {
numbers1[it1->first] = {it1->second, 0}; ++it1;
}
else { numbers1[it2->first] = {0, it2->second}; ++it2;
}
}
// print
std::cout << "Interlaced map (numbers1): "; for (const auto& pair : numbers1) 
{ std::cout << pair.first << ": "
    << pair.second.first << ", "
    << pair.second.second << " ";
}
std::cout << std::endl;
return 0;
}









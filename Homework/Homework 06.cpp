#include <iostream>

inline void swap_no_temp(int& a, int& b) {
    if (&a == &b) return;
    a ^= b;
    b ^= a;
    a ^= b;
}

void findMatches(const int data[], int size1, const int data1[], int size2) {
    std::cout << "\nMatching numbers: ";

for (int i = 0; i < size1; ++i) {
for (int j = 0; j < size2; ++j) {
if (data[i] == data1[j]) {
    std::cout << data[i] << " ";
    break;
}
}
}
    
std::cout << "\n";
}

int main() {
    int data[]  {1, 3, 6, 7, 9};
    int data1[] {5, 3, 3, 11};
const int size_data  = static_cast<int>(sizeof(data)  / sizeof(data[0]));
const int size_data1 = static_cast<int>(sizeof(data1) / sizeof(data1[0]));

const int n = (size_data < size_data1) ? size_data : size_data1;
    for (int i = 0; i < n; ++i) {
    swap_no_temp(data[i], data1[i]);
}

    std::cout << "data  after swap: ";
    for (int i = 0; i < size_data; ++i) std::cout << data[i] << " ";
    std::cout << "\n";

    std::cout << "data1 after swap: ";
    for (int i = 0; i < size_data1; ++i) std::cout << data1[i] << " ";
    std::cout << "\n";

findMatches(data, size_data, data1, size_data1);

    return 0;
}

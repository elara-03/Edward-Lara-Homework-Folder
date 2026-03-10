#include <iostream>
#include <array>

int main() {
    int data[] {1,3,6,7,9};
    int data1[] {5,3,3,11};

size_t size = std::size(data1); 

for(size_t i = 0; i < size; i++) {
    int temp = data[i];
    data[i] = data1[i];
    data1[i] = temp;
}

std::cout << "data: ";
for(size_t i = 0; i < std::size(data); i++) {
std::cout << data[i] << " ";
}

std::cout << "\ndata1: ";
for(size_t i = 0; i < std::size(data1); i++) {
std::cout << data1[i] << " ";
}

}

#include <iostream>
#include <stdexcept>
using namespace std;

//Division Function
double divide(int numerator, int denominator) {
    if (denominator == 0) {
    throw runtime_error("Division by zero is not allowed.");
}

return static_cast<double>(numerator) / denominator;
}

//Array Access Function.
int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
}
    
return arr[index];
}

// Custom Exception Class
class CustomException : public exception {
private:
    string message;
public:
    CustomException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
    return message.c_str();
}
};

// Nested Exception Function
void nestedFunction() {
    throw CustomException("Error in nestedFunction");
}

// Outer Function
void outerFunction() {
    try {nestedFunction();} 
    catch (const CustomException& e) {
        cout << "Caught exception in outerFunction: " << e.what() << endl;
        throw;  // rethrow exception
}
}

int main() {

// Nested Exception Demo
    try {outerFunction();
} 
catch (const CustomException& e) {
    cout << "Caught rethrown exception in main: " << e.what() << endl;
}
cout << endl;

// Division Demo
try {
    int numerator, denominator;
    cout << "Enter numerator: ";        
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

double result = divide(numerator, denominator);
cout << "Result: " << result << endl;
} 
catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}

cout << endl;

//Array Access Demo
try {int size;
    cout << "Enter array size: ";
    cin >> size;

int* arr = new int[size];
for (int i = 0; i < size; ++i) {
        arr[i] = i * 10;  // sample values
}

int index;
    cout << "Enter index to access: ";
        cin >> index;

cout << "Element: " << accessArray(arr, size, index) << endl;
    delete[] arr;

} 

catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}

return 0;
}

#include <iostream>
using namespace std;

// Convert a number to binary
void toBinaryUnsigned(unsigned int x) {
for (int i = 31; i >= 0; i--) {unsigned int bit = (x >> i) & 1;
cout << bit;
if (i % 4 == 0) cout << " ";}
}

// Convert a character to binary
void toBinaryChar(char c) {
unsigned char x = (unsigned char)c; for (int i = 7; i >= 0; i--) {
unsigned char bit = (x >> i) & 1; cout << (int)bit;
if (i % 4 == 0 && i != 0) cout << " ";}
}

// Convert a float to binary
void toBinaryFloat(float f) {
unsigned int* ptr = (unsigned int*)&f;
toBinaryUnsigned(*ptr);
}

int main() {
int choice;cout << "1) char  2) int  3) float\nEnter choice: ";
cin >> choice; if (choice == 1) {
char c;cout << "Enter a character: "; cin >> c;
cout << "Binary: ";toBinaryChar(c);}
else if (choice == 2) {int x;
cout << "Enter an integer: "; cin >> x;
cout << "Binary (32-bit): ";
toBinaryUnsigned((unsigned int)x);}
else if (choice == 3) 
{float f; cout << "Enter a float: ";
cin >> f;
cout << "Binary (IEEE‑754): ";
toBinaryFloat(f);}
else { cout << "Invalid choice.\n";}
return 0;
}




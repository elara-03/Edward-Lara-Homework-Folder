#include <iostream>
constexpr double pi{3.14159265358979};
constexpr double circle(double r)      { return pi * r * r; }
constexpr double square(double s)      { return s * s; }
constexpr double rectangle(double w, double h) { return w * h; }
constexpr double cylinder(double r, double h)  { return pi * r * r * h; }
int main() {
std::cout << "1) Circle area\n"
<< "2) Square area\n"
<< "3) Rectangle area\n"
<< "4) Cylinder volume\n"
<< "Choose: ";
int c;
std::cin >> c;
double a, b;
switch (c) {
case 1:
std::cout << "Radius: "; std::cin >> a;
std::cout << "Area = " << circle(a) << "\n";
break;
case 2:
std::cout << "Side: "; std::cin >> a;
std::cout << "Area = " << square(a) << "\n";
break;
case 3:
std::cout << "Width height: "; std::cin >> a >> b;
std::cout << "Area = " << rectangle(a, b) << "\n";
break;
case 4:
std::cout << "Radius height: "; std::cin >> a >> b;
std::cout << "Volume = " << cylinder(a, b) << "\n";
break;
default:
std::cout << "Invalid option.\n";}
}

#include <iostream>
#include <iomanip>
#include <random>
#include <string>

struct mapbounds {int halfwidth = 10; int halfheight = 10;}
gmap; void createrandommap(int maxwidth = 20, int maxheight = 20)
{ std::random_device rd; 
std::mt19937 gen(rd());
auto evenmaxw = (maxwidth/2) * 2;
auto evenmaxh = (maxheight/2) * 2;
std::uniform_int_distribution<int> wunits(1, evenmaxw / 2);
std::uniform_int_distribution<int> hunits(1, evenmaxh / 2);
int width = 2 * wunits(gen);
int height = 2 * hunits (gen); 
gmap.halfwidth = width/2; 
gmap.halfheight = height/2; }

bool isinsidemap (int x, int y)
{bool withinx = (x >= -gmap.halfwidth) && (x <= gmap.halfwidth);
bool withiny = (y >=-gmap.halfheight) && (y <= gmap.halfheight);
return withinx && withiny; }

void printmapinfo (){ 
    int hw = gmap.halfwidth;
    int hh = gmap.halfheight;
    std::cout << "\n Random map created (centered at 0,0)\n";
    std::cout << " width = " << (2 * hw) << "\n";
    std::cout << " height = " << (2 * hh) << "\n";
    std::cout << " corners (a, b, c, d):\n";
    std::cout << " a(" << -hw << ", " << -hh << ")\n";
    std::cout << " b(" << -hw << ", " << hh << ")\n";
    std::cout << " c(" << hw << ", " << hh << ")\n";
    std::cout << " d(" << hw << ", " << hh << ")\n";
    std::cout << std::endl;}

int main(){ std::cout << "Hello, where r u on da map?\n]n";
createrandommap(20,20);
printmapinfo();
std::string name;
std::cout << "who goes there? ";
std::getline(std::cin, name);
int x = 0, y = 0;
std::cout << "enter your location as coordinates.\n";
std::cout << "x = ";
std::cin >> x;
std::cout << " y = ";
std::cin >> y;
bool inside = isinsidemap (x,y);

if (inside) { 
    bool onboundary =
    (x == -gmap.halfwidth) || (x == gmap.halfwidth) ||
    (y == -gmap.halfheight) || (y == gmap.halfheight);
    if (onboundary) { std::cout << name << ", you are at the edge of the map at(" 
        << x << ", " << y << ").\n";}
    else { std::cout << name << ", you are inside the map at ("
    << x << ", " << y << ").\n";}
} else { std::cout << name << ", you are outside the map at (" 
<< x << ", " << y << ").\n";}

std::cout << "\nok, bye! " << name <<"\n";
return 0; 
}
#include <iostream>
#include <string>

class Adventurer {
public:
    // Basic attack
    void attack() {
        std::cout << "You swing wildly and hit the rock for 1 damage.\n";
    }

    // Attack with specified damage
    void attack(int damage) {
        std::cout << "You strike the rock for " << damage << " damage.\n";
    }

    // Magical attack with spell name and damage
    void attack(const std::string& spell, int damage) {
        std::cout << "You cast " << spell
                  << " and deal " << damage
                  << " magical damage to the rock!\n";
    }
};

int main() {
    Adventurer hero;

    hero.attack();                     // Basic attack
    hero.attack(10);                   // Physical attack
    hero.attack("Fireball", 25);       // Magical attack

    return 0;
}
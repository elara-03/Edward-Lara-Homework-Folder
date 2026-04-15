#include <iostream>
#include <string>

class Adventurer {
public:
    // Attack
    void attack() {
        std::cout << "You punch the rock with all of your might.\n";
}

// Attack with specified damage
    
void attack(int damage) {
        std::cout << "You strike the rock for " << damage << " damage.\n";
    }

// Magic attack with spell name and damage
    void attack(const std::string& spell, int damage) {
        std::cout << "You cast " << spell
                  << " and deal " << damage
                  << " magical damage to the rock!\n";
    }
};

int main() {
    Adventurer hero;

    // Basic attack
    hero.attack();                     
    
    // Physical attack
    hero.attack(1);                   
    
    // Magical attack
    hero.attack("Fireball", 10);       

    return 0;
}
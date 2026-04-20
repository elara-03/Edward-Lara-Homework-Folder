#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon {
protected:
    std::string name;
    int level;

public:
    Pokemon(const std::string& name, int level)
    : name(name), level(level) {}

virtual ~Pokemon() {}

virtual void attack() const = 0;
virtual void defend() const = 0;
virtual void evolve() = 0;

void display() const {
    std::cout << "Name: " << name

<< ", Level: " << level << std::endl;
}
};

#endif
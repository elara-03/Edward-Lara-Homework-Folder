#ifndef DITO_H
#define DITO_H

#include "Pokemon.h"

class Dito : public Pokemon {
private:
    Pokemon* otherPokemon;

public:
    Dito(int level, Pokemon* pokemon): Pokemon("Dito", level), otherPokemon(pokemon) {}

void attack() const override {
    otherPokemon->attack();
}

void defend() const override {
    otherPokemon->defend();
}

void evolve() override {
    std::cout << name << " does not evolve." << std::endl;
}
};

#endif
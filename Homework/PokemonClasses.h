#ifndef POKEMONTYPES_H
#define POKEMONTYPES_H

#include "Pokemon.h"

// Type base class

class PokemonType : public Pokemon {
public:
    PokemonType(const std::string& name, int level): Pokemon(name, level) {}
};

// Type-specific classes

class ElectricPokemon : public PokemonType {
public:
    ElectricPokemon(const std::string& name, int level): PokemonType(name, level) {}

void defend() const override {
    std::cout << name << " defends with electricity!" << std::endl;
}
};

class FirePokemon : public PokemonType {
public:
    FirePokemon(const std::string& name, int level): PokemonType(name, level) {}

void defend() const override {
    std::cout << name << " defends with fire!" << std::endl;
}
};

class GrassPokemon : public PokemonType {
public:
    GrassPokemon(const std::string& name, int level): PokemonType(name, level) {}

void defend() const override {
    std::cout << name << " defends with vines!" << std::endl;
}
};

// Concrete Pokémon

class Pikachu : public ElectricPokemon {
public:
    Pikachu(int level) : ElectricPokemon("Pikachu", level) {}

void attack() const override {
    std::cout << name << " uses Thunderbolt!" << std::endl;
}

void evolve() override {
     std::cout << name << " evolves!" << std::endl;
}
};

class Charmander : public FirePokemon {
public:
    Charmander(int level) : FirePokemon("Charmander", level) {}

void attack() const override {
    std::cout << name << " uses Flamethrower!" << std::endl;
}

void evolve() override {
    std::cout << name << " evolves!" << std::endl;
}
};

class Bulbasaur : public GrassPokemon {
public:
    Bulbasaur(int level) : GrassPokemon("Bulbasaur", level) {}

void attack() const override {
    std::cout << name << " uses Vine Whip!" << std::endl;
}

void evolve() override {
    std::cout << name << " evolves!" << std::endl;
}
};

#endif
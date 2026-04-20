#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon {
protected:
    std::string name;
    int level;

public:
//constructors
Pokemon(const std::string& name, int level): name(name), level(level) {}

//virtual destructor
virtual ~Pokemon() { std::cout<<"Your "+name+" has fainted!"<<std::endl;}

virtual void attack() const = 0;
virtual void defend() const = 0;
virtual void evolve() = 0;

//Function to display the pokemon's details
void display() const {
    std::cout << "Name: " << name

<< ", Level: " << level << std::endl;
}
};

#endif
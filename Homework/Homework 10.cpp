#include "Pokemon.h"
#include "PokemonClasses.h"
#include "Dito.h"
#include "printHeader.h"

int main() {

    Pikachu pikachu(10);
    Charmander charmander(12);
    Bulbasaur bulbasaur(8);
    Dito dito(9000, &bulbasaur);

    Pokemon* pokemons[] = {
        &pikachu, &charmander, &bulbasaur, &dito
    };

    printHeader("Pokemon Battle");

    for (Pokemon* h : pokemons) {
        h->display();
        h->attack();
        h->defend();
        h->evolve();
        std::cout << std::endl;
    }

    return 0;
}
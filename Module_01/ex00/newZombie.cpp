#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie* z;
    z = new Zombie(name);  // Allocation dynamique
    return z;  // Retourne le pointeur
}

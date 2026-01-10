#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
    std::cout << _name << " is born!" << std::endl;
}

Zombie::~Zombie(){
     std::cout << _name << " is dead!" << std::endl;
}

void Zombie::announce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : _name("Unnamed"){
    std::cout << "New Zombie is born" << std::endl;
}

void Zombie::setName(std::string name){
    _name = name;
}

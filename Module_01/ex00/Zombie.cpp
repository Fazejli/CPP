#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
    std::cout << _name << "is born!" << std::endl;
}

Zombie::~Zombie(){
     std::cout << _name << "is dead!" << std::endl;
}

void Zombie::annonce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

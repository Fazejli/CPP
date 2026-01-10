#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Zombie{
    private:
    std::string name;

    public:
    //constructeur
    Zombie(std::string name);
    //destructeur
    ~Zombie();
    //Fctn d'annonce
    void announce(void);
}

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
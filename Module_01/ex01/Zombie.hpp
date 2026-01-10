#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Zombie{
    private:
    std::string _name;

    public:
    //constructeur par defaut
    Zombie();
    //constructeur
    Zombie(std::string name);
    //destructeur
    ~Zombie();
    void announce(void);
    void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name );

#endif
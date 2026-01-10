#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Zombie{
    private:
    std::string _name;
    //Fctn d'annonce
    void announce(void);

    public:
    //constructeur
    Zombie(std::string name);
    //destructeur
    ~Zombie();
    Zombie* newZombie(str name);
	void	randomChump(str name);
};

#endif
#include "Zombie.hpp"
#include <iostream>

int	main() {
	Zombie	*z = NULL;

	z = newZombie("leJ");
	randomChump("leS");
	delete z;
}
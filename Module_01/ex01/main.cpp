#include "Zombie.hpp"
#include <iostream>

int	main() {
	int	i(0);
	int N;
	N = 5;
	Zombie	*horde = zombieHorde(N, "cyril");
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return 0;
}
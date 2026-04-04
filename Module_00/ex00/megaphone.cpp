#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
	int i(1), j(0);

	i = 1;
	if (ac < 2 || (ac == 2 && !av[1]))
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			std::cout << (char)toupper(av[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
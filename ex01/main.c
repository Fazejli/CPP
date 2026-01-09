#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
    int nbr;

    nbr = atoi(av[1]);
    printf("%d %% %d = %d\n", nbr, 8, nbr % 8);
    return (0);
}
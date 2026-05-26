#include "PmergeMe.hpp"

#include <limits.h>
#include <exception>
#include <vector>

int main(int ac, char **av)
{
    if (ac < 2){
        std::cerr << "Error: Usage: ./PMergeMe 3 2 6 1 4\n";
        return 1;
    }
    try{
        PMergeMe pm;
        pm.run(ac, av);
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
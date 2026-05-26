#include "RPN.hpp"

int main(int ac, char **av){
    
    if (ac != 2){
        std::cerr << RED << "Error: Usage: ./RPN \"8 9 * 9 - 1 + 2\"" << RESET << std::endl;
        return 1;}
    RPN list;
    list.calculate(av[1]);
    return 0;
}
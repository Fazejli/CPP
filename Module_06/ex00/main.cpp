#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    std::string toConvert;

    if (ac < 2)
        return (std::cerr << RED << ERR_MSG << RESET << std::endl, 1);
    toConvert = av[1];
    ScalarConverter::convert(toConvert);
    return (0);
}
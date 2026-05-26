#include "BitcoinExchange.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>   
#include <string>
#include <stdlib.h>

int main(int ac, char **av) {
    if (ac != 2){
        std::cerr << RED << "Error: Usage: ./btc <file>\n" << RESET;
        return 1;}
    const std::string arg = av[1];
    if (arg.empty()){
        std::cerr << RED << "Error: Usage: ./btc <file>\n" << RESET;
        return 1;}
    std::ifstream input(arg.c_str());
    if (!input.is_open()){
        std::cerr << RED << "Error: Can't open file \'" << arg << "\'\n" << RESET;
        return 1;}
    std::ifstream db(DATA_BASE);
    if (!db.is_open()){
        std::cerr << RED << "Error: Can't open dataBase\n" << RESET;
        return 1;}
    BitcoinExchange btc;
    btc.printBtc(arg.c_str());
    return 0;
}
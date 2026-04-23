//#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>   
#include <string> 

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

bool isValidValue(std::string value)

bool isValidDate(const std::string date){
    std::string day;
    std::string month;
    std::string year;
    std::istringstream ss(date);
    getline(ss, year, '-');
    getline(ss, month, '-');
    getline(ss, day, '-');

}


int parseFile(std::string arg){
    std::ifstream filename(arg.c_str());
    if (!filename.is_open()){
        std::cerr << RED << "Error: cannot open file " << arg.c_str() << RESET << std::endl;
        return 1;}
    std::string date;
    std::string value;
    std::string line;
    while (getline(filename, line)){
        if (line == "date | value")
            continue ;
        std::istringstream ss(line);
        getline(ss, date, " | ");
        getline(ss, value, " | ");
        if (isValidDate(date) && isValidValue(line)){
            printBTC(date, line);
        }
    }
    std::cout << "Date = " << date << std::endl;
    std::cout << "Value = " << value << std::endl;
    return 0;
}

int main(int ac, char **av){
    
    if (ac != 2){
        std::cerr << RED << "Error: Usage: ./btc <file>\n" << RESET;
        return 1;}
    std::string arg = av[1];
    if (arg.empty()){
        std::cerr << RED << "Error: Usage: ./btc <file>\n" << RESET;
        return 1;}
    //loadDataBase();
    return parseFile(arg);
}
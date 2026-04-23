#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"
#define DATA_BASE "data.csv"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>   
#include <string> 
#include <exception>
#include <ios>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange & src);

        void loadDataBase(const std::string path);
        void printBtc(std::string path);
        float getRate(std::string date) const;
    
    private:
        std::map<std::string, float> _data;

        bool isValidDate(std::string &date) const;
        bool isValidValue(std::string &value, float &output) const;
};

#endif
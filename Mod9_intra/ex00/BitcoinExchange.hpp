#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define DATA_BASE "data.csv"
#include <algorithm>
#include <iostream>
#include <map>

class map;

class BitcoinExchange : public std::map<std::string, int> {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange & src);
        
        private:
        std::string _date;
        float       _val;
};

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &s);

#endif
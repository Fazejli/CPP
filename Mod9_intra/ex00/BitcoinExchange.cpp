#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
        
BitcoinExchange::BitcoinExchange(const BitcoinExchange & src){}
        
BitcoinExchange::~BitcoinExchange(){}
        
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & src){}


std::string BitcoinExchange::getDate() const{
    return _date;
}


std::ostream &operator<<(std::ostream &o, const BitcoinExchange &s){
    o << s.getDate();
    return o;
}

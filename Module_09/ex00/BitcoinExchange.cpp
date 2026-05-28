#include "BitcoinExchange.hpp"
#include "StringUtils.hpp"
#include <exception>

BitcoinExchange::BitcoinExchange(){
    BitcoinExchange::loadDataBase(DATA_BASE);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src){
    this->_data = src._data;
}
        
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & src){
    if (this != &src)
        this->_data = src._data;
    return *this;
}

void BitcoinExchange::loadDataBase(const std::string path){
    std::ifstream db(path.c_str());
    if (!db.is_open()){
        std::cerr << RED << "Error: Can't open data base" << RESET << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(db, line)){
        std::string date;
        std::string price;
        float value;
        if (line == "date,exchange_rate")
            continue ;
        std::istringstream ss(line);
        if (!getline(ss, date, ',') || !getline(ss, price)){
            std::cerr << RED << "Error: Data not found" << RESET << std::endl;
            return ;
        }
        std::istringstream s(price);
        s >> value;
        _data.insert(std::pair<std::string, float>(date, value));
    }
}

bool BitcoinExchange::isValidValue(std::string &value, float &val) const {
    std::string trimmed = trim(value);
    if (trimmed.empty()){
        std::cerr << RED << "Error: not a valid value." << RESET << std::endl;
        return false;
    }
    char *endptr;
    val = std::strtof(trimmed.c_str(), &endptr);
    if (endptr == trimmed.c_str() || *endptr != '\0'){
        std::cerr << RED << "Error: not a valid value." << RESET << std::endl;
        return false;
    }
    if (val < 0.0f){
        std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
        return false;
    }
    if (val > 1000.0f){
        std::cerr << RED << "Error: too large a number." << RESET << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(std::string &data) const {
    std::string date = trim(data);
    if (date.empty())
        return false;

    std::string year, month, day;
    std::istringstream ss(date);
    if (!getline(ss, year, '-') || !getline(ss, month, '-') || !getline(ss, day))
        return false;

    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
        return false;

    for (size_t i = 0; i < year.size(); i++)
        if (!isdigit(year[i])) return false;
    for (size_t i = 0; i < month.size(); i++)
        if (!isdigit(month[i])) return false;
    for (size_t i = 0; i < day.size(); i++)
        if (!isdigit(day[i])) return false;

    int yearNb  = std::atoi(year.c_str());
    int monthNb = std::atoi(month.c_str());
    int dayNb   = std::atoi(day.c_str());

    std::string extra;
    if (getline(ss, extra) && !extra.empty())
        return false;

    if (yearNb <= 0)
        return false;
    if (monthNb <= 0 || monthNb > 12)
        return false;
    if (dayNb <= 0)
        return false;

    bool isLeapYear = (yearNb % 4 == 0 && yearNb % 100 != 0) || (yearNb % 400 == 0);
    int maxDay;
    if (monthNb == 2)
        maxDay = isLeapYear ? 29 : 28;
    else if (monthNb == 4 || monthNb == 6 || monthNb == 9 || monthNb == 11)
        maxDay = 30;
    else
        maxDay = 31;

    if (dayNb > maxDay)
        return false;
    return true;
}

float BitcoinExchange::getRate(std::string date) const {
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it != _data.end() && it->first == date)
        return it->second;
    if (it == _data.begin())
        throw std::runtime_error("no data found (too old).");
    --it;
    return it->second;
}

void BitcoinExchange::printBtc(std::ifstream & db){
    if (!db.is_open()){
        std::cerr << RED << "Error: can't open file" << RESET << std::endl;
        return ;
    }
    std::string line;
    std::string date;
    std::string value;
    float output;
    getline(db, line);
    if (trim(line) != "date | value"){
        std::cerr << RED << "Error: unknown form format" << RESET << std::endl;
        return ;
    }
    while (getline(db, line)){
        if (line.empty())
            continue ;
        std::istringstream ss(line);
        getline(ss, date, '|');
        getline(ss, value, '|');
        if (!isValidDate(date)){
            std::cerr << RED << "Error: bad input => " << RESET << trim(date) << std::endl;
            continue ;
        }
        if (!isValidValue(value, output))
            continue ;
        else {
            try {
                float res = this->getRate(trim(date));
                std::cout << YELLOW << trim(date) << RESET << " => " << YELLOW << trim(value) << RESET << " = " << MAGENTA << formatFloat(res * output) << RESET << std::endl;}
            catch (std::exception & e){
                std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
            }
        }
   }
}


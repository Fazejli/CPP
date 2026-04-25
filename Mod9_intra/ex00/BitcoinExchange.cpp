#include "BitcoinExchange.hpp"

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
        std::cerr << RED << "Error: Can't open data base"  << RESET << std::endl;
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
        if (!getline(ss, date, ',') || !getline(ss, price, ',')){
            std::cerr << RED << "Error: Data not found"  << RESET << std::endl;
            return ;
        }
        std::istringstream s(price);
        s >> value;
        _data.insert(std::pair<std::string, float>(date, value));
    }
}

bool BitcoinExchange::isValidValue(std::string &value, float &val) const {
    if (value.empty())
        return false;
    if (value != "0" && value != "0.0f" && static_cast<float>(std::atof(value.c_str())) == 0){
        std::cerr << RED << "Error: not a valid number."  << RESET << std::endl;
        return false;}
    std::istringstream s(value);
    s >> val && !s.eof();
    if (val < 0.0f ){
        std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
        return false;}
    if (val > 1000.0f){
        std::cerr << RED << "Error: too large a number." << RESET << std::endl;
        return false;}
    return true;
}

bool BitcoinExchange::isValidDate(std::string &data) const {
    if (data.empty())
        return false;
    std::string date = data;
    date.erase(date.length() - 1, 1);
    std::string day;
    std::string month;
    std::string year;
    std::istringstream ss(date);
    getline(ss, year, '-');
    getline(ss, month, '-');
    getline(ss, day, '-');
    int dayNb = std::atoi(day.c_str());
    int monthNb = std::atoi(month.c_str());
    int yearNb = std::atoi(year.c_str());
    bool isLeapYear = (yearNb % 4 == 0 && yearNb % 100 != 0) || yearNb % 400 == 0;
    bool flag = true; //if false alors 30j
    if (year.size() != 4 || yearNb <= 0)
        return false;
    if (month.size() != 2 || monthNb <= 0 || monthNb > 12)
        return false;
    if (day.size() != 2 || dayNb <= 0 || dayNb > 31)
        return false;
    if (monthNb == 2){
        if (!isLeapYear && dayNb > 28)
            return false;
        else if (dayNb > 29)
            return false;
    }
    if (monthNb < 8 && monthNb % 2)
        flag = false;
    else if (monthNb >= 8 && monthNb % 2 == 0)
        flag = false;
    if (flag && dayNb == 31)
        return false;
    return true;
}

float BitcoinExchange::getRate(std::string date) const{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it == _data.begin())
        return -1.0f;
    if (it == _data.end() || it->first != date)
        --it;
    return (it->second);
}

void BitcoinExchange::printBtc(std::string path){
    std::ifstream db(path.c_str());
    if (!db.is_open()){
        std::cerr << RED <<"Error: can't open file" << RESET << std::endl;
    }
    std::string line;
    std::string date;
    std::string value;
    float output;
    getline(db, line);
    if (line != "date | value"){
        std::cerr << RED << "Error: unknown form format" << RESET << std::endl;
        return ;}
    while (getline(db, line)){
        if (line.empty())
            continue ;
        std::istringstream ss(line);
        getline(ss, date, '|');
        getline(ss, value, '|');
        if (!isValidDate(date)){
            std::cerr << RED << "Error: bad input => " << RESET << date << std::endl;
            continue ;
        }
        if (!isValidValue(value, output))
            continue ;
        else{
            float res = this->getRate(date);
            if (res < 0)
                std::cerr << RED << "Error: data not found (too old)" << RESET << std::endl;
            else
                std::cout << YELLOW << date << RESET << "=>" << YELLOW << value << RESET << " = " << MAGENTA << res * output << RESET << std::endl;
        }
    }
}
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

#define ERR_MSG "Error: Invalid input.\nUsage: ./convert <value>."

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <limits>
#include <cmath>
#include <climits>



class ScalarConverter{
    public:
        static void convert(std::string value);
    private:
        ScalarConverter(){};
        ScalarConverter(const ScalarConverter & src);
        ScalarConverter & operator=(const ScalarConverter & src);
        ~ScalarConverter(){};
};

#endif
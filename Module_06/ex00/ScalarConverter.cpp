#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter(const ScalarConverter & src){
    (void)src;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & src){
    (void)src;
    return *this;
}

bool isInt(std::string value){
    std::istringstream s(value);
    int nb;
    return (s >> nb) && s.eof();
}

bool isChar(std::string value){
    std::istringstream s(value);
    std::string c;
    s >> c;
    if (c.length() != 1)
        return (false);
    return s.eof();
}

bool isFloat(std::string value){
    if (value == "nanf" || value == "+inff" || value == "-inff")
        return true;
    if (value.empty() || value[value.length() - 1] != 'f')
        return false;
    std::string newVal = value.substr(0, value.length() - 1);
    std::istringstream s(newVal);
    float nb;
    return (s >> nb) && s.eof();
}

bool isDouble(std::string value){
    if (value == "nan" || value == "+inf" || value == "-inf")
        return true;
    std::istringstream s(value);
    double d;
    return (s >> d) && s.eof();
}

std::string detectType(std::string value){
    if (isChar(value))
        return ("char");
    else if (isInt(value))
        return ("int"); 
    else if (isFloat(value))
        return ("float");
    else if (isDouble(value))
        return ("double");
    return ("unkown");
}

/*void    printFloat(std::string value){}*/

void    printChar(std::string value){
    char c = value[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
//a revoir
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void    printInt(std::string value){
    std::istringstream s(value);
    int nb;
    if (!(s >> nb) || !s.eof()) return ;
    char c = static_cast<char>(nb);
    if (!isprint(c))
        std::cout << "char: non displayable" << std::endl;
    else if (c > 0 && c < 127)
        std::cout << "char: '" << c << "'"<< std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << nb << std::endl;
//a revoir
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

void    printDouble(std::string value){
    std::istringstream s(value);
    double nb;
    s >> nb;
    if (std::isnan(nb) || std::isinf(nb)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else {
        char c = static_cast<char>(nb);
        if (!isprint(c))
            std::cout << "char: non displayable" << std::endl;
        else if (c > 0 && c < 127)
            std::cout << "char: '" << c << "'"<< std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
        std::cout << "double: " << nb << std::endl;
    }
}

void ScalarConverter::convert(std::string value) {
    std::string type = detectType(value);
    
    if (type == "int")
        printInt(value);
    else if (type == "char")
        printChar(value);
    //else if (type == "float")
    //    printFloat(value);
    else if (type == "double")
        printDouble(value);
    else
        std::cout << RED << "Invalid argument" << RED << std::endl;
}


#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath>
#include <limits>

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
    if (value == "nanf" || value == "inff" || value == "+inff" || value == "-inff")
        return true;
    if (value.empty() || value[value.length() - 1] != 'f')
        return false;
    std::string newVal = value.substr(0, value.length() - 1);
    std::istringstream s(newVal);
    float nb;
    return (s >> nb) && s.eof();
}

bool isDouble(std::string value){
    if (value == "nan" || value == "inf" || value == "+inf" || value == "-inf")
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
    return ("unknown");
}

void printFromDouble(double d) {
    std::cout << std::fixed << std::setprecision(1);
    double char_min = 0;
    double char_max = 127;
    if (d < char_min || d > char_max) {
        std::cout << "char: impossible" << std::endl;
    } else {
        char c = static_cast<char>(d);
        if (!std::isprint(static_cast<unsigned char>(c))) {
            std::cout << "char: non displayable" << std::endl;
        } else {
            std::cout << "char: '" << c << "'" << std::endl;
        }
    }
    double int_min = std::numeric_limits<int>::min();
    double int_max = std::numeric_limits<int>::max();
    if (d < int_min || d > int_max || d != static_cast<double>(static_cast<int>(d))) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void printSpecial(std::string value) {
    bool is_neg = (value.length() > 0 && value[0] == '-');
    bool is_nan = value.find("nan") != std::string::npos;

    std::string f_str, d_str;
    if (is_nan) {
        f_str = "nanf";
        d_str = "nan";
    } else {
        f_str = is_neg ? "-inff" : "+inff";
        d_str = is_neg ? "-inf" : "+inf";
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << f_str << std::endl;
    std::cout << "double: " << d_str << std::endl;
}

void printChar(std::string value) {
    double d = static_cast<double>(value[0]);
    printFromDouble(d);
}

void printInt(std::string value) {
    std::istringstream s(value);
    int i;
    s >> i;
    double d = static_cast<double>(i);
    printFromDouble(d);
}

void printFloat(std::string value) {
    bool is_nan = value.find("nan") != std::string::npos;
    bool is_inf = value.find("inf") != std::string::npos;
    if (is_nan || is_inf) {
        printSpecial(value);
    } else {
        std::string val_no_f = value.substr(0, value.length() - 1);
        std::istringstream s(val_no_f);
        float f;
        s >> f;
        printFromDouble(static_cast<double>(f));
    }
}

void printDouble(std::string value) {
    bool is_nan = value.find("nan") != std::string::npos;
    bool is_inf = value.find("inf") != std::string::npos;
    if (is_nan || is_inf) {
        printSpecial(value);
    } else {
        std::istringstream s(value);
        double d;
        s >> d;
        printFromDouble(d);
    }
}

void ScalarConverter::convert(std::string value) {
    std::string type = detectType(value);
    if (type == "unknown") {
        std::cout << RED << "unknown type" << RESET << std::endl;
        return ;
    }
    if (type == "float" || type == "double") {
        bool is_nan = value.find("nan") != std::string::npos;
        bool is_inf = value.find("inf") != std::string::npos;
        if (is_nan || is_inf) {
            printSpecial(value);
        } else {
            if (type == "float") {
                std::string val_no_f = value.substr(0, value.length() - 1);
                std::istringstream s(val_no_f);
                float f;
                s >> f;
                printFromDouble(static_cast<double>(f));
            } else {
                std::istringstream s(value);
                double d;
                s >> d;
                printFromDouble(d);
            }
        }
    } else if (type == "char") {
        printChar(value);
    } else if (type == "int") {
        printInt(value);
    }
}

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return *this;
}

static bool isInt(std::string value)
{
    int nb;
    std::istringstream s(value);
    s >> nb;
    return (!s.fail()) && s.eof();
}

static bool isFloat(std::string value)
{
    if (value == "inff" || value == "-inff" || value == "+inff" || value == "nanf")
        return true;
    if (value[value.length() -1] != 'f')
        return false ;
    if (!isdigit(value[0]) && value[0] != '-' && value[0] != '+')
        return false;
    std::string newVal = value.substr(0, value.length() - 1);
    float f;
    std::istringstream s(newVal);
    s >> f;
    return (!s.fail()) && s.eof();
}

static bool isDouble(std::string value)
{
    if (value == "inf" || value == "-inf" || value == "+inf" || value == "nan")
        return true;
    double d;
    std::istringstream s(value);
    s >> d;
     return ((!s.fail()) || isinf(d)) && s.eof();
}


static std::string detectType(std::string value)
{
    if (value.empty())
        return ("null");
    if (value.length() == 1 && !isdigit(value[0]))
        return ("char");
    else if (isInt(value))
        return ("int");
    else if (isFloat(value))
        return ("float");
    else if (isDouble(value))
        return ("double");
    return ("Unknown");
}

static void printFromDouble(double val)
{
    int nb = static_cast<int>(val);

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

    if (val >= static_cast<double>(INT_MIN) && val <= static_cast<double>(INT_MAX))
        std::cout << "int: " << nb << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << std::scientific << std::setprecision(1) << val << std::endl;
}

static void printSpecials(std::string value){
    std::string newVal = value;
    bool isNeg = (value[0] == '-');

    if (value[0] == '-' || value[0] == '+')
        newVal = value.substr(1, value.length());
    
    if (newVal == "inf" || newVal == "inff"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (isNeg ? "-" : "+") << "inff" << std::endl;
        std::cout << "double: " << (isNeg ? "-" : "+") << "inf" << std::endl;
    }
    else if (value == "nan" || value == "nanf"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
    }
}


void ScalarConverter::convert(std::string value)
{
    std::string type = detectType(value);

    if (type == "Unknown" || type == "null")
    {
        std::cerr << RED << "Invalid argument" << RESET << std::endl;
        return;
    }

    if (value == "nan" || value == "nanf" ||
        value == "inf"  || value == "+inf"  || value == "-inf" ||
        value == "inff" || value == "+inff" || value == "-inff")
    {
        printSpecials(value);
        return;
    }

    if (type == "float")
    {
        std::string newVal = value.substr(0, value.length() - 1);
        std::istringstream s(newVal);
        float f_nbr;
        s >> f_nbr;
        printFromDouble(static_cast<double>(f_nbr));
    } else if (type == "double"){
        std::istringstream s(value);
        double d;
        s >> d;
        printFromDouble(d);
    }
    else if (type == "char")
        printFromDouble(static_cast<double>(value[0]));
    else if (type == "int"){
        std::istringstream s(value);
        int nb;
        s >> nb;
        printFromDouble(static_cast<double>(nb));
    }
}
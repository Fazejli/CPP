#include "ScalarConverter.hpp"
#include <iomanip>
#include <sstream>
#include <cctype>

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
    return (nb) && s.eof();
}

static bool isFloat(std::string value)
{
    if (value == "inff" || value == "-inff" || value == "+inff" || value == "nanf")
        return true;

    std::string newVal = value.substr(0, value.length() - 1);
    float f;
    std::istringstream s(newVal);
    s >> f;
    return (f);
}

static bool isDouble(std::string value)
{
    if (value == "inf" || value == "-inf" || value == "+inf" || value == "nan")
        return true;
    double d;
    std::istringstream s(value);
    s >> d;
    return (d) && s.eof();
}

static void printLiterals(std::string value)
{
    bool is_nan = (value == "nanf" || value == "nan" );
    if (is_nan)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        exit(0);
    }
}

static std::string detectType(std::string value)
{
    if (value.empty())
        return ("null");
    if (value.length() == 1 && !isdigit(value[0]))
        return ("char");
    else if (isInt(value) || value == "0")
        return ("int");
    else if (isDouble(value))
        return ("double");
    else if (isFloat(value))
        return ("float");
    return ("Unknown");
}

static void printFromDouble(double val)
{
    int nb = static_cast<int>(val);

    if (nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(nb))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

    if (nb > INT_MAX || nb < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}

static void printInt(std::string value)
{
    int nb;
    std::istringstream s(value);
    s >> nb;
    printFromDouble(static_cast<double>(nb));
}

void ScalarConverter::convert(std::string value)
{
    std::string type = detectType(value);

    if (type == "Unknown" || type == "null")
    {
        std::cerr << RED << "Invalid argument" << RED << std::endl;
        return;
    }

    if (type == "float" || type == "double")
    {
        printLiterals(value);
        if (type == "float")
        {
            std::string newVal = value.substr(0, value.length() - 1);
            std::istringstream s(newVal);
            float f_nbr;
            s >> f_nbr;
            printFromDouble(static_cast<double>(f_nbr));
        }
        else
        {
            std::istringstream s(value);
            double d;
            s >> d;
            printFromDouble(d);
        }
    }
    else if (type == "char")
        printFromDouble(static_cast<double>(value[0]));
    else if (type == "int")
        printInt(value);
}
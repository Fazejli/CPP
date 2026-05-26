#include "StringUtils.hpp"

#include <sstream>
#include <iomanip>

std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

std::string formatFloat(float value)
{
    std::ostringstream oss;

    oss << std::fixed << std::setprecision(3) << value;
    std::string str = oss.str();
    while (!str.empty() && str[str.size() - 1] == '0')
        str.erase(str.size() - 1);
    if (!str.empty() && str[str.size() - 1] == '.')
        str.erase(str.size() - 1);
    return str;
}
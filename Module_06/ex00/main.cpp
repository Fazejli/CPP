#include "ScalarConverter.hpp"
#include <iostream>

/*//TESTS (kept for reference):

//char
'a'
'z'
'0'
'*'
=> 31 / 127 / 128

//int
0
42
-42
2147483647
-2147483648
=> 2147483648
-2147483649

//float
0.0f
42.0f
-42.0f
4.2f
-4.2f
=> 1e40f
-1e40f
1e400
-1e400

//double
0.0
42.0
-42.0
4.2
-4.2
=> 1e40f
-1e40f
1e400
-1e400


//invalid
abc
4.2ff
--42
++42
42f42
'a
a'
''
"c"
*/

int main(int ac, char **av)
{
    std::string toConvert;

    if (ac != 2){
        std::cerr << RED << ERR_MSG << RESET << std::endl;
        return (1);
    }
    toConvert = av[1];
    ScalarConverter::convert(toConvert);
    return (0);
}
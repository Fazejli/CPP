#include <iostream>
#include <iomanip>
#include <string>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "String address: " << &str << std::endl;
    std::cout << "String's ptr address: " << stringPTR << std::endl;
    std::cout << "String's ref address: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "String value: " << str << std::endl;
    std::cout << "String's ptr value: " << *stringPTR << std::endl;
    std::cout << "String's ref value: " << stringREF << std::endl;

}
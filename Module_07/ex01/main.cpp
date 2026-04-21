#include "Iter.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

template <typename T>
void print(const T& x) {
    std::cout << x << "  ";
}

template <typename T>
void increment(T& x) {
    x++;
}

void toUpper(std::string& s) {
    for (size_t i = 0; i < s.size(); i++) {
        s[i] = std::toupper(s[i]);
    }
}

int main() {

std::cout << GREEN << "== BASIC TEST: `int` ==" << RESET << std::endl;
    int tab[] = {1, 2, 3, 4, 5};
    int len = 5;
    
    std::cout << CYAN << "Print pre increment: " << RESET;
    iter(tab, len, print<int>);

    std::cout << CYAN << "\nPrint after increment: " << RESET;
    iter(tab, len, increment<int>);
    iter(tab, len, print<int>);
    std::cout << std::endl;


std::cout << GREEN << "\n== BASIC TEST: `double` ==" << RESET << std::endl;
    const double dtab[] = {1.1, 2.2, 3.3};
    len = 3;

    std::cout << "Printing.." << std::endl;
    iter(dtab, len, print<double>);
    std::cout << std::endl;

    
std::cout << GREEN << "\n== BASIC TEST: `char` ==" << RESET << std::endl;
    std::string stab[] = {"heLLo", "woRlD"};
    len = 2;

    std::cout << CYAN << "Original strings: " << RESET;
    iter(stab, len, print<std::string>);
    std::cout << std::endl;

    std::cout << CYAN << "After ToUpper call: " << RESET;
    iter(stab, len, toUpper);
    iter(stab, len, print<std::string>);
    std::cout << std::endl;

    return 0;
}
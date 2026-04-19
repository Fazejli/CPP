#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"



class D : public Base {public: D(){}};

int main(){
    std::srand(std::time(0));

    std::cout << GREEN << "== Pointer Tests ==" << RESET << std::endl;
    Base *p = generate();
    identify(p);
    delete p;

    std::cout << GREEN << "== Reference Tests ==" << RESET << std::endl;
    Base *r = generate();
    identify(*r);
    delete r;

    std::cout << GREEN << "== Unknown Class test ==" << RESET << std::endl;
    Base *l = new D;
    
    std::cout << "Indentify with pointer: ";
    identify(l);

    std::cout << "Indentify with reference: ";
    identify(*l);
    delete l;
    
    return 0;
}
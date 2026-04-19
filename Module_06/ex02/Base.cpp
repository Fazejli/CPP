#include "Base.hpp"

Base * generate(void){
    switch (rand() % 3) {
        case 0: std::cout << CYAN << "// Class A created..." << RESET << std::endl; 
            return (new A);
        case 1: std::cout << CYAN << "// Class B created..." << RESET << std::endl;
            return (new B);
        case 2: std::cout << CYAN << "// Class C created..." << RESET << std::endl;
            return (new C);
    }
    return 0;
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << RED << "Unknown class." << RESET << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;}
    catch(std::exception & e) {}
    
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(std::exception & e) {}

    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }    catch(std::exception & e) {}

    std::cout << RED << "Unknown class." << RESET << std::endl;
}


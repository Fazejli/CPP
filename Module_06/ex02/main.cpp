#include "Base.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"


int main(){
    std::srand(std::time(0));
    std::cout << GREEN << "== Pointer Tests ==" << RESET << std::endl;
    try {
        Base *p = generate();
        identify(p);
        delete p;
    }
    catch(std::exception &e){
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "== Reference Tests ==" << RESET << std::endl;
    try {
        Base *r = generate();
        identify(*r);
        delete r;
    }
    catch(std::exception &e){
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
    return 0;
}
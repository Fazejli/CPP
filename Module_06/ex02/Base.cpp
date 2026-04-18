#include "Base.hpp"

Base * generate(void){
    if (rand() % 3 == 0)
    {
        if (rand() % 2 == 0){
            Base *aClass = new A;
            return (dynamic_cast<Base*>(aClass));}
        Base *bClass = new B;
        return (dynamic_cast<Base*>(bClass));
    }
    else{
        Base *cClass = new C;
        return (dynamic_cast<Base*>(cClass));
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
        std::cout << "Unkown class." << std::endl;
}

void identify(Base& p) {
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unkown class." << std::endl;
}


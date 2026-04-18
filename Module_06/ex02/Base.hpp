#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <typeinfo>


class Base {
    public:
        virtual ~Base(){};
};

class A : public Base {
    public:
        A(){std::cout << "DEBUG: A Constructor called." << std::endl;}
};
class B : public Base {
    public:
        B(){std::cout << "DEBUG: B Constructor called." << std::endl;}
};
class C : public Base {
    public:
        C(){std::cout << "DEBUG: C Constructor called." << std::endl;}
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
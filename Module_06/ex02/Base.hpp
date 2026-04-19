#ifndef BASE_HPP
#define BASE_HPP

#define RED     "\033[31m"
#define RESET   "\033[0m"
#define CYAN    "\033[36m"


#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ostream>

class Base {
    public:
        virtual ~Base(){};
};

class A : public Base {public: A(){}};
class B : public Base {public: B(){}};
class C : public Base {public: C(){}};

/* DEBUG */
//  class A : public Base {public: A(){std::cout << "A constructor" << std::endl;}};
//  class B : public Base {public: B(){std::cout << "B constructor" << std::endl;}};
//  class C : public Base {public: C(){std::cout << "C constructor" << std::endl;}};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
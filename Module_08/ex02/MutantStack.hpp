#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack <T> {
    public:
        MutantStack() : std::stack<T>(){}
        MutantStack(const MutantStack &othr) : std::stack<T>(othr){}
        MutantStack &operator=(const MutantStack &othr){
            if (this != &othr)
                std::stack<T>::operator=(othr);
            return *this;
        }
        ~MutantStack(){}

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin() {return this->c.begin();};
        iterator end() {return this->c.end();};
        const_iterator begin() const {return this->c.begin();};
        const_iterator end() const {return this->c.end();};
};

#endif
#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

class Span{
    public:
        Span();
        Span(unsigned int size);
        Span(const Span &src);
        Span &operator=(const Span & src);
        ~Span();

        void addNumber(int nbr);
        int shortestSpan();
        int longestSpan();

        template <typename T>
        void addRange(T begin, T end) {
            while (begin != end){
                addNumber(*begin);
                begin++;
            }
        }

    private:
        unsigned int _n;
        std::vector<int> _vector;
};



#endif
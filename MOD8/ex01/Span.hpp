#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

template <typename T>
class Span{
    private:
        std::vector<T> _arr;
        unsigned int _size;
    public:
        Span();
        Span(unsigned int nbr);
        Span(const Span & src);
        ~Span();

        Span &operator=(const Span &src);

        void addNumber(T nbr);
        unsigned int size() const { return _arr.size(); }
        T operator[](unsigned int i) const { return _arr[i]; }
        T shortestSpan() const;
        T longestSpan() const;
};

#include "Span.cpp"

#endif
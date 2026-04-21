#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <algorithm>

template <typename T>
class Span{
    private:
        T *_arr;
        unsigned int _size;
    public:
        Span();
        Span(unsigned int nbr);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);

        void addNumber(T nbr);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

std::ostream &operator<<(std::ostream &o, const Span<int> &s);

#endif
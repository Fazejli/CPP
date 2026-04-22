#include "Span.hpp"

Span::Span() : _n(0){}

Span::~Span(){}

Span::Span(unsigned int size) : _n(size){}

Span::Span(const Span &src) : _n(src._n), _vector(src._vector){}

Span &Span::operator=(const Span & src){
    if (this != &src){
        this->_n = src._n;
        this->_vector = src._vector;
    }
    return (*this);
}

void Span::addNumber(int nbr){
    if (_vector.size() == _n)
        throw std::length_error("Error: Container is full.");
    else
        _vector.push_back(nbr);
}

int Span::shortestSpan(){
    if (_vector.size() <= 1)
        throw std::length_error("Error: Container size <= 1.");
    std::vector<int> sorted = _vector;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); i++){
        int span = sorted[i] - sorted[i - 1];
        if (span < min)
            min = span; 
    }
    return min;
}

int Span::longestSpan(){
    if (_vector.size() <= 1)
        throw std::length_error("Error: Container size <= 1.");
    std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
    std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
    return (*max - *min);
}
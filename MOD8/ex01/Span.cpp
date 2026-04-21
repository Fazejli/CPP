#include "Span.hpp"

template <typename T>
Span<T>::Span(): _size(0) {}

template <typename T>
Span<T>::Span(unsigned int nbr) : _size(nbr) {}
        
template <typename T>
Span<T>::Span(const Span & src) { *this = src; }

template <typename T>
Span<T>::~Span() {}

template <typename T>
Span<T> &Span<T>::operator=(const Span &src){
    if (this != &src){
        this->_size = src._size;
        this->_arr = src._arr;
    }
    return *this;
}

template <typename T>
void Span<T>::addNumber(T nbr){
    if (this->_arr.size() >= this->_size)
        throw std::length_error("Error: Can't add new attribute (Container complete)");
    else
        this->_arr.push_back(nbr);
}

template <typename T>
T Span<T>::shortestSpan() const{
    if (this->_arr.size() <= 1)
        throw std::length_error("ShortestSpan Error: Container size <= 1");
    
    std::vector<T> sorted = this->_arr;
    std::sort(sorted.begin(), sorted.end());
    
    T min = sorted[1] - sorted[0];
    for (unsigned int i = 2; i < sorted.size(); i++){
        T span = sorted[i] - sorted[i - 1];
        if (span < min)
            min = span;
    }
    return min;
}


template <typename T>
T Span<T>::longestSpan() const{
    if (this->_arr.size() <= 1)
        throw std::length_error("LongestSpan Error: Container size <= 1");
    
    std::vector<T> sorted = this->_arr;
    std::sort(sorted.begin(), sorted.end());
    
    return sorted.back() - sorted.front();
}
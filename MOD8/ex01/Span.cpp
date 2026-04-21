#include "Span.hpp"

template<typename T>
Span<T>::Span(){
    this->_size = 0;
    this->_arr = new T(1);
}

template<typename T>
Span<T>::Span(unsigned int nbr){
    this->_size = nbr;
    this->_arr = new T(nbr);
}

template<typename T>
Span<T>::~Span(){
    delete[] this->_arr;
}

template<typename T>
Span<T>::Span(const Span & src){
    *this = src;
}

template<typename T>
Span<T> &Span<T>::operator=(const Span &src){
    if (this != &src){
        delete[] this->_arr;
        this->_size = src._size;
        this->_arr = new T(_size);
        for (int i = 0; i < _size; i++)
            this->_arr[i] = src._arr[i];
    }
    return *this;
}

template<typename T>
void Span<T>::addNumber(T nbr){
    if (_arr.size() == nbr)
        throw std::length_error();
    else{
        _arr.push_back(nbr);
        _size++;}
}

template<typename T>
unsigned int Span<T>::shortestSpan() const{
    if (this->_size <= 1)
        return NULL;
}

template<typename T>
unsigned int Span<T>::longestSpan() const{
    if (this->_size <= 1)
        return NULL;    
}


template<typename T>
std::ostream &operator<<(std::ostream &o, const Span<T> &s){
    o << s.getSize();
    return o;
}

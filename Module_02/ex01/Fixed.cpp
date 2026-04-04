#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int nbr){
    std::cout << "Int constructor called" << std::endl;
    this->_value = nbr * 256 ;
}

Fixed::Fixed(const float nbr){
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(nbr * 256);
}

float   Fixed::toFloat(void) const {
    return ((float)_value / 256);
}

int     Fixed::toInt(void) const {
    return (_value / 256);
}

Fixed & Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &src){
    o << src.toFloat();
    return (o);
}

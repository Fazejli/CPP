#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0){
}

Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed &other){
    *this = other;
}

Fixed::Fixed(const int nbr){
    this->_value = nbr * 256;
}

Fixed::Fixed(const float nbr){
    this->_value = roundf(nbr * 256);
}

float   Fixed::toFloat(void) const {
    return ((float)_value / 256);
}
int     Fixed::toInt(void) const {
    return (_value / 256);
}

Fixed & Fixed::operator=(const Fixed &other){
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(Fixed other) const{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(Fixed other) const{
    return (this->toFloat() < other.toFloat());
}
bool Fixed::operator>=(Fixed other) const{
    return (this->toFloat()>= other.toFloat());
}
bool Fixed::operator<=(Fixed other) const{
    return (this->toFloat() <= other.toFloat());
}
bool Fixed::operator==(Fixed other) const{
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(Fixed other) const{
    return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(Fixed other) const {
    Fixed temp(this->toFloat() + other.toFloat());
    return (temp);
}

Fixed Fixed::operator-(Fixed other) const {
    Fixed temp(this->toFloat() - other.toFloat());
    return (temp);
}

Fixed Fixed::operator*(Fixed other) const {
    Fixed temp(this->toFloat() * other.toFloat());
    return (temp);
}

Fixed Fixed::operator/(Fixed other) const {
    if (other.toFloat() != 0)
        return Fixed(this->toFloat() / other.toFloat());
    return Fixed(this->toFloat());
}

Fixed &Fixed::operator++(void){
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed temp(*this);
    ++this->_value;
    return (temp);
}

Fixed &Fixed::operator--(void){
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed temp(*this);
    --this->_value;
    return (temp);
}

Fixed &Fixed::min(Fixed &fp1, Fixed &fp2) {
    if (fp1.toFloat() > fp2.toFloat())
        return (fp2);
    return (fp1);
}

const Fixed &Fixed::min(const Fixed &fp1, const Fixed &fp2) {
    if (fp1.toFloat() > fp2.toFloat())
        return (fp2);
    return (fp1);
}

Fixed &Fixed::max(Fixed &fp1, Fixed &fp2){
    if (fp1.toFloat() < fp2.toFloat())
        return (fp2);
    return (fp1);
}

const Fixed &Fixed::max(const Fixed &fp1, const Fixed &fp2) {
    if (fp1.toFloat() < fp2.toFloat())
        return (fp2);
    return (fp1);
}

int Fixed::getRawBits(void) const {
    return (this->_value);
}

void Fixed::setRawBits(int const raw){
    this->_value = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &src){
    o << src.toFloat();
    return (o);
}

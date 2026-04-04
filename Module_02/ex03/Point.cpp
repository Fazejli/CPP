#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){
    //std::cout << "Default constructor Point called" << std::endl;
}

Point::~Point(){
    //std::cout << "Default destructor Point called" << std::endl;
}

Point::Point(const float x_val, const float y_val) : _x(x_val), _y(y_val){
    //std::cout << "Assignment constructor Point called" << std::endl;
}

Point::Point(const Point &src) : _x(src.getXValue()), _y(src.getYValue()){
    //std::cout << "Copy constructor Point called" << std::endl;
}

Point& Point::operator=(const Point &src) {
    //std::cout << "operator overload called" << std::endl ;
    (void)src;
    return (*this);
}

Fixed Point::getX(void) const {
    return (this->_x);
}

Fixed Point::getY(void) const {
    return (this->_y);
}

float Point::getXValue(void) const{
    return(this->getX().toFloat());
}

float Point::getYValue(void) const{
    return(this->getY().toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const p){
    float     prod1;
    float     prod2;
    float     prod3;

    prod1 = (b.getXValue() - a.getXValue()) * (p.getYValue() - a.getYValue()) - (b.getYValue() - a.getYValue()) * (p.getXValue() - a.getXValue());
    prod2 = (c.getXValue() - b.getXValue()) * (p.getYValue() - b.getYValue()) - (c.getYValue() - b.getYValue()) * (p.getXValue() - b.getXValue());
    prod3 = (a.getXValue() - c.getXValue()) * (p.getYValue() - c.getYValue()) - (a.getYValue() - c.getYValue()) * (p.getXValue() - c.getXValue());
    if ((prod1 > 0 && prod2 > 0 && prod3 > 0) || (prod1 < 0 && prod2 < 0 && prod3 < 0))
        return true;
    else
        return false;
}
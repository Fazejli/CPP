#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <stdio.h>
#include <cmath>

class Point {
    public:
        Point(void);
        Point(const float x_val, const float y_val);
        Point(const Point &src);
        ~Point();

        Point & operator=(const Point &other) ;

        Fixed getX(void) const;
        Fixed getY(void) const;
        float     getXValue(void) const;
        float     getYValue(void) const;
    private:
        const Fixed _x;
        const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
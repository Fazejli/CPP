#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>


class Fixed {
    public:
        Fixed(void);
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed(const int nbr);
        Fixed(const float nbr);

        float   toFloat(void) const;
        int     toInt(void) const;
        Fixed & operator=(const Fixed &other);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _value;
        static const int _nbBits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &src);

#endif
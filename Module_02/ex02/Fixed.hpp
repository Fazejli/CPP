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

        bool operator>(Fixed other) const;
        bool operator<(Fixed other) const;
        bool operator>=(Fixed other) const;
        bool operator<=(Fixed other) const;
        bool operator==(Fixed other) const;
        bool operator!=(Fixed other) const;

        Fixed operator+( Fixed other) const;
        Fixed operator-( Fixed other) const;
        Fixed operator*( Fixed other) const;
        Fixed operator/( Fixed other) const;

        static Fixed &min(Fixed &fp1, Fixed &fp2);
        const static Fixed &min(const Fixed &fp1, const Fixed &fp2);
        static Fixed &max(Fixed &fp1, Fixed &fp2);
        const static Fixed &max(const Fixed &fp1, const Fixed &fp2);

        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _value;
        static const int _nbBits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &src);

#endif
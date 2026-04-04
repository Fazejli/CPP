#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>


class Fixed {
    public:
        Fixed(void);
        ~Fixed();
        Fixed(const Fixed &other);

        Fixed & operator=(const Fixed &other);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _value;
        static const int _nbBits = 8;
};

#endif
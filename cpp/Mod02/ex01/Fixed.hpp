#ifndef FIXED_HPP
# define FIXED_HPP
#include <cmath>
#include <iostream>
#include <ostream>


class Fixed{

public:
    Fixed();
    Fixed(const Fixed &t);
    Fixed(const int);
    Fixed(const float);
    Fixed&   operator=(const Fixed& F);
    float   toFloat() const;
    int     toInt() const;
    int     getRawBits();
    ~Fixed();
private:
    int RawValue;
    static const int fractional_bits = 8;

};

std::ostream &operator<<(std::ostream&, Fixed const&);

#endif
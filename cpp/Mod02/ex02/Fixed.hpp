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
    Fixed&   operator=(const Fixed & F);
    bool   operator>(const Fixed & F);
    bool   operator<(const Fixed & F);
    bool   operator>=(const Fixed & F);
    bool   operator<=(const Fixed & F);
    bool   operator==(const Fixed & F);
    bool   operator!=(const Fixed & F);
    Fixed   operator*(const Fixed & F);
    Fixed   operator/(const Fixed & F);
    Fixed   operator-(const Fixed & F);
    Fixed   operator+(const Fixed & F);
    Fixed	operator++();
    Fixed	operator++(int);
    Fixed	operator--();
    Fixed	operator--(int);
    friend std::ostream &operator<<(std::ostream&,const Fixed&);
    float   toFloat() const;
    int     toInt() const;
    int     getRawBits();
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    ~Fixed();
private:
    int RawValue;
    static const int fractional_bits = 8;
};


#endif
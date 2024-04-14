#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

public:
    Fixed();
    Fixed(const Fixed &t);
    void operator=(const Fixed& F);
    int getRawBits();
    ~Fixed();
private:
    int RawValue;
    static const int fractional_bits = 8;

};
#endif
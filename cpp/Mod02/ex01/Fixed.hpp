#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

public:
    Fixed();
    Fixed(const Fixed &t);
    Fixed(const int);
    Fixed(const float);
    void    operator<<();
    void    operator=(const Fixed& F);
    float   toFloat() const;
    int     toint() const;
    int     getRawBits();
    ~Fixed();
private:
    int RawValue;
    static const int fractional_bits = 8;

};
#endif
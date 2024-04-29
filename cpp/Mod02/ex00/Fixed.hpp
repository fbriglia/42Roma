#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

public:
    Fixed();
    Fixed(const Fixed &t);
    Fixed& operator=(const Fixed& F);
    int getRawBits() const;
    void setRawBits(int const raw);
    ~Fixed();
private:
    int RawValue;
    static const int fractional_bits = 8;

};

 

#endif
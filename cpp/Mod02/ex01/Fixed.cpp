#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): RawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Fixed const &F)
{
    stream << F.toFloat();
    return(stream);
}

Fixed::Fixed(const int val)
{
    RawValue = val * pow(2,fractional_bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
    RawValue = val * pow(2,fractional_bits);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& F)
{
    std::cout << "Copy assignment operator called" << std::endl;
    RawValue = F.RawValue;
    return(*this);
}

float Fixed::toFloat() const
{
    return(RawValue/pow(2,fractional_bits));
}

int Fixed::toInt() const
{
    return(RawValue/pow(2,fractional_bits));
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return RawValue;
}

void Fixed::setRawBits(int const raw)
{
    RawValue = raw;
}
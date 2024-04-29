#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed():RawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const& f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this= f;
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& F)
{
    std::cout << "Copy assignment operator called" << std::endl;
    RawValue = F.RawValue;
    return (*this);
}

void Fixed::setRawBits(int const raw)
{
    RawValue = raw;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return RawValue;
}
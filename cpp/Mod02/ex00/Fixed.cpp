#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed():RawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const&){
    std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(const Fixed& F)
{
    std::cout << "Copy assignment operator called" << std::endl;
    RawValue = F.RawValue;
}

int Fixed::getRawBits()
{
    std::cout << "getRawBits member function called" << std::endl;
    return RawValue;
}
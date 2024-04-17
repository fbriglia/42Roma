#include "Fixed.hpp"
#include <iostream>

// CONSTRUCTORS
Fixed::Fixed(): RawValue(0){
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val){
    RawValue = val * pow(2,fractional_bits);
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val){
    RawValue = val * pow(2,fractional_bits);
}

Fixed::Fixed(Fixed const& f){
    *this = f;
}

// DECONSTRUCTOR
Fixed::~Fixed(){
    // std::cout << "Destructor called" << std::endl;
}

// OPERATORS
Fixed& Fixed::operator=(const Fixed& F)
{
    RawValue = F.RawValue;
    return(*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

bool   Fixed::operator>(const Fixed& F)
{
    return (this->getRawBits() > F.RawValue);
}
bool   Fixed::operator<(const Fixed & F)
{
    return (this->getRawBits() < F.RawValue);
}
bool   Fixed::operator>=(const Fixed & F)
{
    return (this->getRawBits() >= F.RawValue);
}
bool   Fixed::operator<=(const Fixed & F)
{
    return (this->getRawBits() <= F.RawValue);
}
bool   Fixed::operator==(const Fixed & F)
{
    return (this->getRawBits() == F.RawValue);
}
bool   Fixed::operator!=(const Fixed & F)
{
    return (this->getRawBits() != F.RawValue);
}
Fixed   Fixed::operator*(const Fixed & F)
{
    return (Fixed(this->toFloat() * F.toFloat()));
}
Fixed   Fixed::operator/(const Fixed & F)
{
    return (Fixed(this->toFloat() / F.toFloat()));
}
Fixed   Fixed::operator+(const Fixed & F)
{
    return (Fixed(this->toFloat() + F.toFloat()));
}
Fixed   Fixed::operator-(const Fixed & F)
{
    return (Fixed(this->toFloat() - F.toFloat()));
}

Fixed	Fixed::operator++()
{
	this->RawValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->RawValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}


// FUNCTIONS
Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.RawValue > b.RawValue)
		return (b);
	return (a);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.RawValue < b.RawValue)
		return (b);
	return (a);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}
float Fixed::toFloat() const
{
    return(RawValue/pow(2,fractional_bits));
}

int Fixed::toInt() const
{
    return(RawValue/pow(2,fractional_bits));
}

int Fixed::getRawBits()
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (RawValue);
}
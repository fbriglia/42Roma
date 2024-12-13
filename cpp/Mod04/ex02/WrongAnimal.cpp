#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& A)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = A;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& A)
{
    std::cout << "WrongAnimal override = called" << std::endl;
    if (this != &A)
        type = A.type;
    return(*this);
}

std::string WrongAnimal::getType() const
{
    return (type);
}

void WrongAnimal::makeSound() const 
{
    std::cout << "Default Sound" << std::endl;
}
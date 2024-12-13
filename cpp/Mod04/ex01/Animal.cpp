#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& A)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = A;
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& A)
{
    std::cout << "Animal override = called" << std::endl;
    if (this != &A)
        type = A.type;
    return(*this);
}

std::string Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const 
{
    std::cout << "Default Sound" << std::endl;
}
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor called" << std::endl;
    Animal::type = "Dog";
}

Dog::Dog(const Dog& D) : Animal()
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    *this = D;
}

Dog::~Dog()
{
    std::cout << "Dog Deconstructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& D)
{
    std::cout << "Dog = override called" << std::endl;
    if (this != &D)
        type = D.type;
    return(*this);
}

std::string Dog::getType() const
{
    return(type);
}

void Dog::makeSound() const 
{
    std::cout << "Woof" << std::endl;
}
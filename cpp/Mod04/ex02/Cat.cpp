#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat()
{
    std::cout << "Cat Constructor called" << std::endl;
    Animal::type = "Cat";
    CatBrain = new Brain();
}

Cat::Cat(const Cat& C): Animal()
{
    std::cout << "Cat CopyConstructor called" << std::endl;
    *this = C;
}

Cat::~Cat()
{
    delete CatBrain;
    std::cout << "Cat Deconstructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& C)
{
    std::cout << "Cat override = called" << std::endl;
    if (this != &C)
        type = C.type;
    return(*this);
}

std::string Cat::getType() const
{
    return(type);
}

void Cat::makeSound() const 
{
    std::cout << "Miao" << std::endl;
}
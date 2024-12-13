#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Constructor called" << std::endl;
    WrongAnimal::type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& C): WrongAnimal()
{
    std::cout << "WrongCat CopyConstructor called" << std::endl;
    *this = C;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Deconstructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& C)
{
    std::cout << "WrongCat override = called" << std::endl;
    if (this != &C)
        type = C.type;
    return(*this);
}

std::string WrongCat::getType() const
{
    return(type);
}

void WrongCat::makeSound() const 
{
    std::cout << "Miao" << std::endl;
}
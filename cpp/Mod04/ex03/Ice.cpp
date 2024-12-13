#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(): AMateria("ice"){}

Ice::Ice(const Ice& C): AMateria(C){}

Ice::~Ice(){}

std::string const & Ice::getType() const
{
    return(type);
}

Ice& Ice::operator=(const Ice&C)
{
    type = C.type;
    return (*this);
}


Ice* Ice::clone()const
{
    return(new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
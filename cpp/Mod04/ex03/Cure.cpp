#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure(): AMateria("cure"){}

Cure::Cure(const Cure& C): AMateria(C){}

Cure::~Cure(){}

std::string const & Cure::getType() const
{
    return(type);
}

Cure& Cure::operator=(const Cure&C)
{
    type = C.type;
    return (*this);
}

Cure* Cure::clone()const
{
    return(new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
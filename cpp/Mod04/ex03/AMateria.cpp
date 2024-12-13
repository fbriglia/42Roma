#include "AMateria.hpp"

AMateria::AMateria(): type(""){}

AMateria::AMateria(std::string const &type): type(type){}

AMateria::AMateria(const AMateria& A)
{
    type = A.type;
}


AMateria& AMateria::operator=(const AMateria& A)
{
    if (this != &A)
        type = A.type;
    return(*this);
}

std::string const & AMateria::getType() const
{
    return(type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "AMateria use called" << std::endl;
}
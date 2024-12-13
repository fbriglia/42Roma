#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        Materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& M)
{
    *this = M;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& M)
{
    for (int i = 0; i < 4; i++)
    {
        if (Materias[i])
            delete Materias[i];
        Materias[i] = M.Materias[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource() 
{
    for (int i = 0; i < 4; i++)
        delete Materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i<4; i++)
    {
        if (!Materias[i])
        {
            Materias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if(Materias[i] && Materias[i]->getType() == type)
            return(Materias[i]->clone());
    }
    return(0);
}
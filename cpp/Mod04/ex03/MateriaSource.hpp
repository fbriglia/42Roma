#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource: public IMateriaSource
{
    private:
        AMateria* Materias[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource&);
        MateriaSource& operator=(const MateriaSource&);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
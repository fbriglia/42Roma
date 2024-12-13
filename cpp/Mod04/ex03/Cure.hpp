#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria 
{
    public:
        Cure();
        Cure(const Cure&);
        Cure& operator=(const Cure&);
        std::string const& getType()const;
        Cure* clone()const;
        void use(ICharacter&);
        ~Cure();
};

#endif
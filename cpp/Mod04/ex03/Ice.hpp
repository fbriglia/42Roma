#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria 
{
    public:
        Ice();
        Ice(const Ice&);
        Ice& operator=(const Ice&);
        std::string const& getType()const;
        Ice* clone()const;
        void use(ICharacter&);
        ~Ice();
};

#endif
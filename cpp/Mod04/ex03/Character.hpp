#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
    private:
        std::string _Name;
        AMateria* Materias[4];
    public:
        Character();
        Character(std::string);
        Character(const Character&);
        Character& operator=(const Character&);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int i);
        void use(int i, ICharacter& target);
};

#endif
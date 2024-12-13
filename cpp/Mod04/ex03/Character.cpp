#include "Character.hpp"

Character::Character(): _Name("")
{
    for (int i = 0; i < 4; i++)
        Materias[i] = 0;
}

Character::Character(std::string str): _Name(str)
{
    for (int i = 0; i < 4; i++)
        Materias[i] = 0;
}
Character::Character(const Character& C)
{
    *this = C;
}
Character& Character::operator=(const Character& C)
{
    for (int i = 0; i < 4; i++)
    {
        if (Materias[i])
            delete Materias[i];
        Materias[i] = C.Materias[i];
    }
    _Name = C._Name;
    return (*this);
}
Character::~Character() 
{
    for (int i = 0; i < 4; i++)
        delete Materias[i];
}

std::string const & Character::getName() const
{
    return(_Name);
}

void Character::equip(AMateria* m)
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
void Character::unequip(int i)
{
    if (i < 4 && i >= 0)
        Materias[i] = 0;
}
void Character::use(int i, ICharacter& target)
{
    if (i < 4 && i >= 0 && Materias[i])
    {
        std::cout << " " << _Name << " ";
        Materias[i]->use(target);
    }
}
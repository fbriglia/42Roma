#ifndef HUMANB_H
# define HUMANB_H
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB();
        Weapon* weapon;
        std::string name;
        void attack();
        void setWeapon(Weapon &weapon);
};
#endif
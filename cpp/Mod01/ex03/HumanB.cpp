#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
   weapon = weapon;
}
HumanB::~HumanB(){}


void HumanB::attack()
{
    std::cout << this->name << " attacks with " << this->weapon->get_type() << std::endl; 
}
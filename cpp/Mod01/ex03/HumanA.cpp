#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon){}
HumanA::~HumanA(){}

void HumanA::attack()
{
    std::cout << name << " attacks with " << weapon.get_type() << std::endl; 
}
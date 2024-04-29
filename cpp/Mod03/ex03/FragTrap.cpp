#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("", 100, 100, 30)
{
    std::cout << "FT Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string input): ClapTrap(input, 100, 100, 30)
{
    std::cout << "FT Constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& C): ClapTrap(C.getName(), C.getHitPoints(), C.getEnergyPoints(), C.getAttackDamage()){}


FragTrap & FragTrap::operator=(FragTrap const& C) 
{
    if (this != &C)
    {
        this->_AttackDamage = C._AttackDamage;
        this->_EnergyPoints = C._EnergyPoints;
        this->_HitPoints = C._HitPoints;
        this->_Name = C._Name;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FT Destrutor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    std::cout << getName() << " attacks " << target + ", causing " << getAttackDamage() << " damage" << std::endl;
}

void highFiveGuys()
{
    std::cout << "High Five Guys!" << std::endl;
}
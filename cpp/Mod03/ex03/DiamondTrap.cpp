#include "DiamondTrap.hpp"
#include <cstring>

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(){
    std::cout << "DT Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string input): ClapTrap(std::strcat(&input[0], "_clap_name"), 100, 50, 30), ScavTrap(), FragTrap()
{
    _Name = input;
    std::cout << "DT Constructor called // DT name " << _Name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& DT): ClapTrap(getName().insert(getName().length(), "_clap_name"), DT.getHitPoints(), DT.getEnergyPoints(), DT.getAttackDamage()), ScavTrap(), FragTrap()
{
    std::cout << "DT Copy Constructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const& C) 
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

void DiamondTrap::whoAmI()
{
    std::cout << "I Am " << _Name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DT Destructor called" << std::endl;
}


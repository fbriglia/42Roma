#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("", 100, 50, 20)
{
    std::cout << "ST Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string input): ClapTrap(input, 100, 50, 20)
{
    std::cout << "ST Constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& C): ClapTrap(C.getName(), C.getHitPoints(), C.getEnergyPoints(), C.getAttackDamage()){}


ScavTrap & ScavTrap::operator=(ScavTrap const& C) 
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

ScavTrap::~ScavTrap()
{
    std::cout << "ST Destrutor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << getName() << " attacks " << target + ", causing " << getAttackDamage() << " damage" << std::endl;
}

void guardGate()
{
    std::cout << "Guard Mode activate" << std::endl;
}
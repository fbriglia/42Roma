#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(ClapTrap const& C): _Name(C.getName()), _HitPoints(C.getHitPoints()), _EnergyPoints(C.getEnergyPoints()), _AttackDamage(C.getAttackDamage()){}

ClapTrap::ClapTrap(std::string input, int a, int b, int c):_Name(input), _HitPoints(a), _EnergyPoints(b), _AttackDamage(c)
{
   std::cout << "CT Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "CT Destrutor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const& C) 
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

void ClapTrap::attack(const std::string& target)
{
    std::cout << _Name << " attacks " << target + ", causing " << _AttackDamage << " damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    _HitPoints -= amount;
    _EnergyPoints--;
    if (_EnergyPoints <= 0)
    {
        std::cout << _Name << " is out of energy " << std::endl;
        return;
    }
    if (_HitPoints <= 0)
    {
        std::cout << _Name << " takes " << amount << " damage, he is dead " << std::endl;
        return;
    }
    std::cout << _Name << " takes " << amount << " damage, his remaining life is " << _HitPoints << ". His energy points are " << _EnergyPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    _EnergyPoints--;
    _HitPoints += amount;
    if (_EnergyPoints <= 0)
    {
        std::cout << _Name << " is out of energy " << std::endl;
        return;
    }
    if (_HitPoints <= 0)
    {
        std::cout << _Name << " can't repair, he is dead " << std::endl;
        return;
    }
    std::cout << _Name << " takes " << amount << " life back, his remaining life is " << _HitPoints << ". His energy points are " << _EnergyPoints << std::endl;
}

std::string ClapTrap::getName()const
{
    return(_Name);
}

int ClapTrap::getHitPoints()const
{
    return(_HitPoints);
}
int ClapTrap::getEnergyPoints()const
{
    return(_EnergyPoints);
}
int ClapTrap::getAttackDamage()const
{
    return(_AttackDamage);
}
void ClapTrap::setName(std::string input)
{
    _Name = input;
}
void ClapTrap::setHitPoints(int x)
{
    _HitPoints = x;
}
void ClapTrap::setEnergyPoints(int x)
{
    _EnergyPoints = x;
}
void ClapTrap::setAttackDamage(int x)
{
    _AttackDamage = x;
}



#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string, int, int, int);
        ClapTrap(const ClapTrap&);
        ClapTrap & operator=(ClapTrap const& C);
        std::string getName()const;
        int getHitPoints()const;
        int getEnergyPoints()const;
        int getAttackDamage()const;
        void setName(std::string);
        void setHitPoints(int);
        void setEnergyPoints(int);
        void setAttackDamage(int);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ~ClapTrap();
    protected:
        std::string _Name;
        int         _HitPoints;
        int         _EnergyPoints;
        int         _AttackDamage;

};

#endif
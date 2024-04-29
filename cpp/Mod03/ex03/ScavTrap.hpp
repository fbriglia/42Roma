#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap 
{
    public:
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&);
        ScavTrap & operator=(ScavTrap const& C);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};

#endif
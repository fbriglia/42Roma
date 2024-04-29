#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap 
{
    public:
        DiamondTrap();
        DiamondTrap(std::string);
        DiamondTrap(const DiamondTrap&);
        DiamondTrap & operator=(DiamondTrap const& C);
        using ScavTrap::attack;
        void whoAmI();
        ~DiamondTrap();
    private:
        std::string _Name;
};


#endif
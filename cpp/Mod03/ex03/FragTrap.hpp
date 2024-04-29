#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap 
{
    public:
        FragTrap();
        FragTrap(std::string);
        FragTrap(const FragTrap&);
        FragTrap & operator=(FragTrap const& C);
        ~FragTrap();
        void attack(const std::string& target);
        void highFiveGuys();
};

#endif
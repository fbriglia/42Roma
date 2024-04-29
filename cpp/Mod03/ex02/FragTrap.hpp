#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap 
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
#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap(std::string);
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
    private:
        std::string _Name;
        int         _HitPoints;
        int         _EnergyPoints;
        int         _AttackDamage;

};
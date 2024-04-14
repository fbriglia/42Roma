#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie
{
    public:
        Zombie(std::string);
        ~Zombie();
        void announce();
    private:
        std::string name;
};

Zombie* new_zombie(std::string name);
void    random_chump(std::string name);

#endif
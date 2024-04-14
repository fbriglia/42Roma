#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie
{
    public:
        Zombie(std::string);
        Zombie();
        ~Zombie();
        void announce();
        void set_name(std::string name);
    private:
        std::string name;
};

Zombie* new_zombie(std::string name);
Zombie* zombie_horde(std::string name, int n);

#endif
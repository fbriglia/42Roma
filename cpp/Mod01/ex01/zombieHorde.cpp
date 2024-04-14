#include "Zombie.hpp"

Zombie* zombie_horde(std::string name, int n)
{

    Zombie* horde = new Zombie[n];
    for (int i = 0; i < n; i++)
    {
        horde[i].set_name(name);
    }
    return horde;
}
#include "Zombie.hpp"

Zombie* new_zombie(std::string name)
{
    return(new Zombie(name));
}
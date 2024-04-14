#include "Zombie.hpp"

void random_chump(std::string name)
{
    Zombie another_zombie = Zombie(name);

    another_zombie.announce();
}
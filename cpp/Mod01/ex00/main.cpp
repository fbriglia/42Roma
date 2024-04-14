#include "Zombie.hpp"

int main()
{
    Zombie *my_new_zombie;

    random_chump("Luca");
    my_new_zombie = new_zombie("Damiano");
    my_new_zombie->announce();
    delete my_new_zombie;
}
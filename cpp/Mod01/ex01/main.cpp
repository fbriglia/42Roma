#include "Zombie.hpp"

int main()
{
    Zombie *horde = zombie_horde("Zombie", 5);

    for (int i = 0; i < 5; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
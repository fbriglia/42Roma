#include "Zombie.hpp"

Zombie :: Zombie(std::string zombie_name) : name(zombie_name){}

Zombie :: ~Zombie(){
    std::cout << this->name << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}


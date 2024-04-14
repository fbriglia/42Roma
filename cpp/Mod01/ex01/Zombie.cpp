#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::Zombie()
{
    this->name = "default";
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " is dead" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

#include "Weapon.hpp"

Weapon::Weapon(std::string type_name): type(type_name){}

Weapon::Weapon():type(""){}

Weapon::~Weapon(){}

const std::string& Weapon::get_type()
{
    return(this->type);
}

void Weapon::setType(std::string tipo)
{
    this->type = tipo;
}

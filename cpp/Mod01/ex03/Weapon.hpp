#ifndef WEAPON_H
# define WEAPON_H
#include <iostream>

class Weapon{
    public:
        Weapon(std::string type);
        Weapon();
        ~Weapon();
        const std::string& get_type();
        void setType(std::string tipo);
    private:
        std::string type;

};
#endif
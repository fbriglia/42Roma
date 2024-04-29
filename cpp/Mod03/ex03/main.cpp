#include "DiamondTrap.hpp"

int main(){
    DiamondTrap a("Damiano");

    a.attack("Federico");
    a.takeDamage(5);
    a.whoAmI();
    a.beRepaired(5);
    a.takeDamage(5);

}
#include "ClapTrap.hpp"

int main(){
    ClapTrap a("Damiano");
    ClapTrap b = a;
    b.attack("Federico");
    a.takeDamage(5);
    a.beRepaired(5);
    a.takeDamage(5);

}
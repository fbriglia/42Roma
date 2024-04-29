#include "FragTrap.hpp"

int main(){
    FragTrap a("Damiano");

    a.attack("Federico");
    a.takeDamage(5);
    a.beRepaired(5);
    a.takeDamage(5);

}
#include "Harl.hpp"

Harl::Harl(){
    fn[0].level = "debug";
    fn[0].fn = &Harl::debug;
    fn[1].level = "info";
    fn[1].fn = &Harl::info;
    fn[2].level = "warning";
    fn[2].fn = &Harl::warning;
    fn[3].level = "error";
    fn[3].fn = &Harl::error;
}

Harl::~Harl(){}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money.\
     You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
    years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    int i = 0;
    while (i < 4)
    {
        if (fn[i].level == level)
        {
            (this->*fn[i].fn)();
            return;
        }
        i++;
    }
}


#include "Intern.hpp"
#include "AForm.hpp"

AForm*  newShrub(std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm*  newRobot(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm*  newPres(std::string target)
{
    return new PresidentialPardonForm(target);
}

Intern::Intern() 
{
    fn[0].fn = &newShrub;
    fn[0].name = "ShrubberyCreationForm";
    fn[1].fn = &newRobot;
    fn[1].name = "RobotomyRequestForm";
    fn[2].fn = &newPres;
    fn[2].name = "PresidentialPardonForm";
}

Intern::Intern(const Intern& I){
    *this = I;
}
Intern& Intern::operator=(const Intern& I)
{
    (void)I;
    return *this;
}

AForm*  Intern::makeForm(std::string name , std::string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (name == fn[i].name)
        {
            std::cout << "Intern creates " << fn[i].name << std::endl;
            return this->fn[i].fn(target);
        }
    }
    std::cout << "No form named " << name << std::endl;
    return 0;
}
Intern::~Intern(){}
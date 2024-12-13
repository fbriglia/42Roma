#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <exception>

int main(void) 
{
    Intern I;
    AForm* SCF = I.makeForm("ShrubberyCreationForm", "Francesco");
    AForm* RRF = I.makeForm("RobotomyRequestForm","Mario");
    AForm* PPF = I.makeForm("PresidentialPardonForm", "Luca");
    Bureaucrat C("Francesco", 5);
    try {
    SCF->beSigned(C); 
    SCF->execute(C);
    RRF->beSigned(C); 
    RRF->execute(C);
    PPF->beSigned(C); 
    PPF->execute(C);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete SCF;
    delete RRF;
    delete PPF;

}
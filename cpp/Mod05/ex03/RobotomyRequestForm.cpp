#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _Target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& PPF) : AForm()
{
    *this = PPF;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& PPF)
{
    _Target = PPF._Target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)const
{
    if ((!getStatus()) || getMinGradeExe() < executor.getGrade())
        throw AForm::GradeTooLowException();
    std::cout << "* DRILLING NOISE * ";
    if (time(0) % 2 == 0)
        std::cout << "* " <<_Target << " HAS BEEN ROBOTOMIZED *" << std::endl;
    else
        std::cout << "* ROBOTOMIZATION FAILED *" << std::endl;
    
}

RobotomyRequestForm::~RobotomyRequestForm(){}
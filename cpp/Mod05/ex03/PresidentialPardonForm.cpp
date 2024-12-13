#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , _Target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& PPF): AForm()
{
    *this = PPF;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& PPF)
{
    _Target = PPF._Target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
    if ((!getStatus()) || getMinGradeExe() < executor.getGrade())
        throw AForm::GradeTooLowException();
    std::cout << "Informs that " << _Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

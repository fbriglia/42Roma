#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137){} 

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _Target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& PPF): AForm()
{
    *this = PPF;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& PPF)
{
    _Target = PPF._Target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
    if (!getStatus() || getMinGradeExe() < executor.getGrade())
    {
        std::cout << getStatus() << " || "<< executor.getGrade() << "  " << getMinGradeExe()<< std::endl;
        throw AForm::GradeTooLowException();
    }
    std::string file_name = _Target+"_shrubbery";
    std::ofstream fileOut;
    fileOut.open(file_name.c_str());
    if (!fileOut.is_open())
        return;
    fileOut << "ciao";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}
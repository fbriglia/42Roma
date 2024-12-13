#include "AForm.hpp"

AForm::AForm(): _Name("(null)"), _Signed(false), _MinGradeSign(0), _MinGradeExe(0) {}
 
AForm::AForm(std::string name, int MinSign, int MinExe): _Name(name),  _Signed(false), _MinGradeSign(MinSign), _MinGradeExe(MinExe) {}

AForm::AForm(const AForm& F): _Name(F._Name),  _MinGradeSign(F._MinGradeSign), _MinGradeExe(F._MinGradeExe)
{
    *this = F;
}

AForm& AForm::operator=(const AForm& F) 
{
    _Signed = F._Signed;
    return (*this);
}

AForm::~AForm(){}

std::string AForm::getName()const
{
    return(_Name);
}

bool    AForm::getStatus()const
{
    return (_Signed);
}

int     AForm::getMinGradeSign()const
{
    return(_MinGradeSign);
}

int     AForm::getMinGradeExe()const
{
    return (_MinGradeExe);
}

std::ostream& operator<<(std::ostream& o, const AForm& obj)
{
    o << "Form Name: " << obj.getName() << ", is signed: "
     << obj.getStatus()<< ", Min grade to sign: " << obj.getMinGradeSign() 
     << ", Min grade to execute: " << obj.getMinGradeExe() << std::endl;
     return (o);
}

void AForm::beSigned(Bureaucrat& B)
{
    if (_MinGradeSign < B.getGrade())
        throw AForm::GradeTooLowException();
    std::cout << B.getName() << " signed form " << _Name << std::endl;
    _Signed = true;
}

const char * AForm::GradeTooHighException::what() const throw() 
{
    return "TooHighException";
}

const char * AForm::GradeTooLowException::what() const throw() 
{
    return "TooLowException";
}
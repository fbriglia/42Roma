#include "Form.hpp"

Form::Form(): _Name("(null)"), _Signed(false), _MinGradeSign(0), _MinGradeExe(0) {}
 
Form::Form(std::string name, int MinSign, int MinExe): _Name(name),  _Signed(false), _MinGradeSign(MinSign), _MinGradeExe(MinExe) {}

Form::Form(const Form& F): _Name(F._Name),  _MinGradeSign(F._MinGradeSign), _MinGradeExe(F._MinGradeExe)
{
    *this = F;
}

Form& Form::operator=(const Form& F) 
{
    _Signed = F._Signed;
    return (*this);
}

Form::~Form(){}

std::string Form::getName()const
{
    return(_Name);
}

bool    Form::getStatus()const
{
    return (_Signed);
}

int     Form::getMinGradeSign()const
{
    return(_MinGradeSign);
}

int     Form::getMinGradeExe()const
{
    return (_MinGradeExe);
}

std::ostream& operator<<(std::ostream& o, const Form& obj)
{
    o << "Form Name: " << obj.getName() << ", is signed: "
     << obj.getStatus()<< ", Min grade to sign: " << obj.getMinGradeSign() 
     << ", Min grade to execute: " << obj.getMinGradeExe() << std::endl;
     return (o);
}

void Form::beSigned(Bureaucrat B)
{
    if (_MinGradeSign < B.getGrade())
        throw Form::GradeTooLowException();
    _Signed = true;
}

const char * Form::GradeTooHighException::what() const throw() 
{
    return "TooHighException";
}

const char * Form::GradeTooLowException::what() const throw() 
{
    return "TooLowException";
}
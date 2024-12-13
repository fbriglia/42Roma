#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _Name(""), _Grade(151){
    std::cout << "B Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _Name(name), _Grade(151)
{
    if (grade <= 0)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _Grade = grade;
    std::cout << "B Constructed with Name " << _Name << " and Grade " << _Grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& B)
{
    std::cout << "B Copy Constructor called" << std::endl;
    *this = B;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& B)
{
    if (B._Grade <= 0)
        throw GradeTooHighException();
    if (B._Grade > 150)
        throw GradeTooLowException();
    _Grade = B._Grade;
    _Name = B._Name;
    return (*this);
}

int Bureaucrat::getGrade()const{
    return(_Grade);
}

std::string Bureaucrat::getName()const {
    return(_Name);
}

void    Bureaucrat::higherGrade(){
    
    this->_Grade--;
    if (this->_Grade < 1)
        throw GradeTooHighException();
}

void    Bureaucrat::lowerGrade(){
    
    this->_Grade++;
    if (this->_Grade > 150)
        throw GradeTooHighException();
}

void    Bureaucrat::signForm(AForm& F)
{
    try{
        F.beSigned(*this);
        std::cout << "Bureaucrat " << _Name << " signed form " 
        << F.getName() << std::endl;
    }
    catch (std::exception &e){
        std::cout << *this << " couldn't sign " << F.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & F)const
{
    try{
        F.execute(*this);
        std::cout << "Bureaucrat " << _Name << " signed form " 
        << F.getName() << std::endl;
    }
    catch (std::exception &e){
        std::cout << *this << " couldn't execute " << F.getName() << " because " << e.what() << std::endl;
    }   
}


Bureaucrat::~Bureaucrat(){
    std::cout << "B Deconstructor called" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj) 
{
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return o;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "TooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "TooLowException";
}
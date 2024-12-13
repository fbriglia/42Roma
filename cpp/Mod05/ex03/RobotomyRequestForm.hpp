#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm&);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm&);
        void execute(Bureaucrat const & executor)const;
        ~RobotomyRequestForm();
    private:
        std::string _Target;
};


#endif
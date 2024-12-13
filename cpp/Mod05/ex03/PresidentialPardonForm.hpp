#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm&);
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
        void execute(Bureaucrat const & executor)const;
        ~PresidentialPardonForm();
    private:
        std::string _Target;
};


#endif
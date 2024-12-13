#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:
        struct  t_fn{
            std::string name;
            AForm* (*fn)(std::string target);
        };

    public:
        Intern();
        Intern(const Intern&);
        Intern& operator=(const Intern&);
        AForm*  makeForm(std::string, std::string);
        t_fn fn[4];
        ~Intern();
    
};

#endif
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>


class Bureaucrat 
{
    public:
        Bureaucrat();
        Bureaucrat(std::string, int);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        std::string getName()const;
        int         getGrade()const;
        void        higherGrade();
        void        lowerGrade();
        ~Bureaucrat();
    protected:
        std::string const _Name;
        int         _Grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj);

#endif
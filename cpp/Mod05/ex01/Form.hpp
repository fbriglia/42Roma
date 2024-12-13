#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;
#include <iostream>
#include <stdexcept>

class Form 
{
    public:
        Form();
		Form(std::string, int, int);
        Form(const Form&);
        Form& operator=(const Form&);
        ~Form();

		std::string getName()const;
		bool 		getStatus()const;
		int			getMinGradeSign()const;
		int			getMinGradeExe()const;
		void		beSigned(Bureaucrat);

		class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

    private:
        const std::string   _Name;
        bool				_Signed;
		const	int			_MinGradeSign;
		const	int			_MinGradeExe;
};

std::ostream & operator<<(std::ostream & o, Form const & obj);

#endif
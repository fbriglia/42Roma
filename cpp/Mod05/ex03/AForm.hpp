#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;
#include <iostream>
#include <stdexcept>

class AForm 
{
    public:
        AForm();
		AForm(std::string, int, int);
        AForm(const AForm&);
        AForm& operator=(const AForm&);
        virtual ~AForm();

		std::string getName()const;
		bool 		getStatus()const;
		int			getMinGradeSign()const;
		int			getMinGradeExe()const;
		void		beSigned(Bureaucrat&);
        virtual void    execute(Bureaucrat const & executor)const = 0;

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

std::ostream & operator<<(std::ostream & o, AForm const & obj);

#endif
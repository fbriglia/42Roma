#include "Bureaucrat.hpp"

int main(void) 
{
    Form Form("Ciao", 100, 10);
	try 
	{
        Bureaucrat bureaucrat("bob", 150);
        bureaucrat.signForm(Form);
        std::cout << bureaucrat << std::endl;
    }
    catch (Form::GradeTooHighException &e) 
	{
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e) 
	{
        std::cerr << e.what() << std::endl;
    }
}
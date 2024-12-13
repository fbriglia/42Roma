Name = Bureaucrat
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
all: $(Name)

$(Name):
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(Name)

clean: 
	rm -f $(Name) *_shrubbery

fclean: clean

re: clean all

.PHONY: all clean re
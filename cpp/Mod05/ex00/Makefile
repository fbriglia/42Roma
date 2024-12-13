Name = Bureaucrat
SRC = main.cpp Bureaucrat.cpp
all: $(Name)

$(Name):
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(Name)

clean: 
	rm -f $(Name)

fclean: clean

re: clean all

.PHONY: all clean re
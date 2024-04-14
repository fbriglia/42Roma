NAME	:=	Harl2.0
SRC		:=	Harl.cpp \
			main.cpp \

OBJ		:=	$(SRC:.cpp=.o)

CXX		:=	c++

CXXFLAGS	:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


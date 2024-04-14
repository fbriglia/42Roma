NAME	:= Fixed
SRCS	:= main.cpp Fixed.cpp
OBJS	:= $(SRCS:.cpp=.o)

CXX		:= c++
CXXFLAGS:= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
CC = c++
NAME = pmergeme
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY: all clean fclean re

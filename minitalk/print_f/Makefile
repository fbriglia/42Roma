NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c \
	  

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ) 

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"
	


re: fclean all


.PHONY: all, clean, fclean, re
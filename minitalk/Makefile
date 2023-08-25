SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

comp_ft_printf:
	@make -C print_f all
	
all: comp_ft_printf server client

bonus: server client

server: server.o
	$(CC) -o $@ $< print_f/libftprintf.a

client: client.o
	$(CC) -o $@ $< print_f/libftprintf.a

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)
	make -C print_f clean
	
fclean: clean
	rm -f server client print_f/libftprintf.a

re: fclean all

.PHONY: all bonus libft clean fclean re
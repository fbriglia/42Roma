#####   COLORS   #####

END				= \033[0m

GREY			= \033[30m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
BLUE			= \033[34m
PURPLE			= \033[35m
CYAN			= \033[36m

HIGH_RED		= \033[91m

#####   INFO   #####

NAME			= so_long

#####   COMMANDS   #####

CC				= gcc
EXTENSION		= c
CFLAGS			= -Wall -Wextra -Werror -g -Wno-unused-result
MINILIBX	=	make -C mlx_linux
MLX			=	mlx_linux/libmlx.a

EXECUTION		= ./$(NAME) map/classic.ber
MD				= mkdir -p
RM				= rm -rf
TAR_EXCLUSIONS	= --exclude=".git" \
				  --exclude=".vscode" \
				  --exclude="objs" \
				  --exclude="._" \
				  --exclude="*.DS_Store"
TAR				= tar $(TAR_EXCLUSIONS) -cf

#####   GIT   #####

ADD = git add .
COMMIT = git commit -m
PUSH = git push

#####   RESOURCES   #####

INCLUDE			= includes
SRC_DIR			= sources
OBJ_DIR			= objs

SRCS			= $(foreach DIR, $(SRC_SUB_DIRS), $(wildcard $(DIR)/*.$(EXTENSION)))
OBJS			= ./sources/ft_itoa.o ./printf/ft_putnbr.o ./printf/ft_printfutils.o ./printf/ft_printf.o ./get_next_line/get_next_line.o ./get_next_line/get_next_line_utils.o ./sources/map.o ./sources/put_images.o ./sources/moves.o ./sources/so_long.o ./sources/enemy.o ./sources/enemy_utils.o ./sources/check.o ./sources/utils_varie.o

PRINTF_DIR = printf/
PRINTF_LIB = printf/libftprintf.a

#####   BASE RULES   #####

all: $(NAME) 


$(NAME): $(OBJ)

$(NAME): $(OBJS)
# @ $(MINILIBX)
	@make -C $(PRINTF_DIR)
	make -C mlx_linux/
	$(CC) $(OBJS) $(PRINTF_LIB) $(MLX) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	# -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
#  @ $(CC) $(MLX) $(LINKER) $(CFLAGS) $(OBJS) -o $@
	@ echo "$(GREEN)[+] $(NAME) compiled$(END)"

%.o: %.c
	# $(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	$(CC) $(CFLAGS) -I $(INCLUDE) -Imlx_linux -O3 -c $< -o $@

# %.o: %.c
# 	@ echo "$(BLUE)[+] $@ compiled$(END)"

$(OBJ_SUB_DIRS):
	@ $(MD) $(OBJ_SUB_DIRS)
	@ echo "$(PURPLE)[+] $(SRC_DIR) remapped into $(OBJ_DIR) $(END)"


clean:
	@ $(RM) $(OBJS)
	@ echo "$(YELLOW)[+] $(OBJ_DIR) cleaned$(END)"

fclean: clean
	@ $(RM) $(NAME) $(PRINTF_LIB) $(MLX) mlx_linux/libmlx_Linux.a
	@ echo "$(YELLOW)[+] $(NAME) fcleaned$(END)"

re: fclean all

bonus: all



#####   EXTRA RULES   #####

test: all
	clear
	@ $(EXECUTION)

run: test
rrun: fclean test

tar: fclean
	@ $(TAR) ../$(NAME).tar .
	@ echo "$(GREEN)[+] Made tar$(END)"

val: all
	valgrind --leak-check=full --show-leak-kinds=all $(EXECUTION)
var: val

git:
	@ $(eval MESSAGE := $(or $(m), $(error Usage: make commit m="<commit message>")))
	@ $(ADD)
	@ $(COMMIT) $(MESSAGE)
	@ $(PUSH)clear

setup:
	@ echo "# dirs\n.vscode\n$(OBJ_DIR)\n\n# files\n$(NAME)\n._*\n.DS_Store" > .gitignore
	@ $(MD) $(SRC_DIR) $(INCLUDE)
	@ echo "$(GREEN)[+] Setup completed$(END)"


#####   PHONY   #####

.PHONY: all clean fclean re

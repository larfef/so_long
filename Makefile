NAME    =       so_long
SRCS    =       display.c event.c gnl.c main.c mapdup.c map_parsing.c utils.c
INC     =       -I include
CFLAGS  =       -Wall -Wextra -Werror -fsanitize=address $(INC)
LIB     =       -L libft -L ft_printf -L mlx -lft -lftprintf -lmlx
MACOS   =       -framework Opengl -framework Appkit
OBJS    =       $(SRCS:.c=.o)

$(NAME): $(OBJS)
		make -C libft
		make -C ft_printf
		make -C mlx
		$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIB) $(MACOS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
		@echo "Compilation terminée"

clean:
		rm -f $(OBJS)
		make -C libft clean
		make -C ft_printf clean
		make -C mlx clean

fclean: clean
		make -C libft fclean
		make -C ft_printf fclean
		rm -f $(NAME)

re: fclean all

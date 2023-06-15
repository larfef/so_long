NAME	=	so_long

SRCS	=	display.c event.c gnl.c main.c mapdup.c map_parsing.c utils.c

INC		=	-I include

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address $(INC)

LIB		=	-L libft -L ft_printf -L mlx -lft -lftprintf -lmlx 

MACOS	=	-framework Opengl -framework Appkit

OBJS	=	$(SRCS:.c=.o)

GCC		=	gcc $(OBJS) -fsanitize=address -o $(NAME) $(LIB) $(MACOS)

all : $(OBJS)
	make -C libft
	make -C ft_printf
	make -C mlx
	$(GCC)
	@echo "Compilation terminée"

clean : 
	rm -f $(OBJS)
	make -C libft clean 
	make -C ft_printf clean
	make -C mlx clean

fclean : 
	make -C . clean
	make -C libft fclean
	make -C ft_printf fclean
	rm $(NAME)

re : 	
	make -C . clean
	make -C . fclean
	make -C . all
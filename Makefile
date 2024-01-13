NAME	=	so_long
DOTO	=	objs
SRCS	=	src/display.c src/event.c src/gnl.c src/main.c src/mapdup.c src/map_parsing.c src/utils.c
INC		=	-I inc -I ft_printf -I libft/inc
CFLAGS	=	-Wall -Wextra -Werror $(INC)
LIB		=	-L libft -L ft_printf -L mlx -lft -lftprintf -lmlx
MACOS	=	-framework Opengl -framework Appkit
OBJS	=	$(addprefix objs/, $(notdir $(SRCS:.c=.o)))

GREEN		= \033[0;32m
RED			= \033[0;31m
LIGHTBLUE	= \033[1;34m
NC			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C ft_printf
	make -C mlx
	gcc $(CFLAGS) $(OBJS) -o $@ $(LIB) $(MACOS)
	@echo "$(GREEN)Compilation successful$(NC)\n"

objs/%.o: src/%.c | objs
	gcc $(CFLAGS) -c $< -o $@

objs:
	mkdir -p objs

clean:
	make -C libft clean
	make -C ft_printf clean
	make -C mlx clean
	@if [ -e objs ]; then \
		echo "\n$(GREEN)__Cleaning objects$(NC)"; \
		echo "$(LIGHTBLUE)=> rm -rf objs\n$(NC)"; \
		/bin/rm -rf objs; \
	else \
		echo "\n $(RED)No object files to clean$(NC)"; \
	fi

fclean: clean
		make -C libft fclean
		make -C ft_printf fclean
	@if [ -e $(NAME) ]; then \
		echo "\n$(GREEN)__Cleaning library$(NC)"; \
		echo "$(LIGHTBLUE)=> rm -f $(NAME)$(NC)\n"; \
		/bin/rm -f $(NAME); \
	else \
		echo " $(RED)$(NAME) doesn't exist$(NC)\n"; \
	fi	

re: fclean all

.PHONY: all clean fclean re
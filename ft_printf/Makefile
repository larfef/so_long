NAME	=	libftprintf.a
SRCS	=	src/display.c src/display_2.c src/ft_printf.c
INC		=	-I inc
CFLAGS	=	-Wall -Wextra -Werror $(INC)
DOTO	=	objs
OBJS	=	$(addprefix objs/, $(notdir $(SRCS:.c=.o)))

GREEN		= \033[0;32m
RED			= \033[0;31m
LIGHTBLUE	= \033[1;34m
NC			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

objs/%.o: src/%.c | $(DOTO)
	gcc $(CFLAGS) -c $< -o $@

objs:
	mkdir -p $(DOTO)

clean:
	@if [ -e objs ]; then \
		echo "\n$(GREEN)__Cleaning objects$(NC)"; \
		echo "$(LIGHTBLUE)=> rm -rf objs\n$(NC)"; \
		/bin/rm -rf objs; \
	else \
		echo "\n $(RED)No object files to clean$(NC)"; \
	fi


fclean: clean
	@if [ -e $(NAME) ]; then \
		echo "\n$(GREEN)__Cleaning library$(NC)"; \
		echo "$(LIGHTBLUE)=> rm -f $(NAME)$(NC)\n"; \
		/bin/rm -f $(NAME); \
	else \
		echo " $(RED)$(NAME) doesn't exist$(NC)\n"; \
	fi

re: fclean all

.PHONY: all clean fclean re 

NAME	=	libft.a
DOTO	=	objs
INC		=	-I inc
SRCS	=	src/ft_check_quote.c src/ft_isdigit.c src/ft_memcpy.c src/ft_split.c \
        	src/ft_strlen.c src/ft_tolower.c src/ft_atoi.c src/ft_isprint.c src/ft_memmove.c \
			src/ft_strchr.c src/ft_strmapi.c src/ft_toupper.c src/ft_bzero.c src/ft_itoa.c \
			src/ft_memset.c src/ft_strdup.c src/ft_strncmp.c src/ft_calloc.c src/ft_putchar_fd.c \
			src/ft_striteri.c src/ft_strnstr.c src/ft_isalnum.c src/ft_putendl_fd.c src/ft_strjoin.c \
			src/ft_strrchr.c src/ft_isalpha.c src/ft_memchr.c src/ft_putnbr_fd.c src/ft_strlcat.c \
			src/ft_strtrim.c src/ft_isascii.c src/ft_memcmp.c src/ft_putstr_fd.c src/ft_strlcpy.c src/ft_substr.c
CFLAGS	=	-Wall -Wextra -Werror $(INC)
OBJS	=	$(addprefix objs/, $(notdir $(SRCS:.c=.o)))

GREEN		= \033[0;32m
RED			= \033[0;31m
LIGHTBLUE	= \033[1;34m
NC			= \033[0m

ifeq ($(shell test -t 1),1)
	GREEN		= \e[32m
	RED			= \e[31m
	LIGHTBLUE	= \e[1;34m
	NC			= \e[0m
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

objs/%.o: src/%.c | objs
	gcc $(CFLAGS) -c $< -o $@

objs:
	mkdir -p objs

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

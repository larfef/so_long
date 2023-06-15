NAME	=	libftprintf.a
SRCS	=	display.c display_2.c ft_printf.c 
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror

all :	$(NAME)
$(NAME)	:	$(OBJS)
	@ar rc $(NAME) $(OBJS)

clean :
	@rm -f $(OBJS)
fclean :	clean
	@rm -f $(NAME)
re :	fclean	all

.PHONY :	all clean fclean re 

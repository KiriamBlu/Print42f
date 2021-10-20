
NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			printing_utilities.c \
			conversion_utilities.c

OBJS	= 	${SRCS:.c=.o}

CC		= gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

AR		=	ar rcs



$(NAME)	:	$(OBJS) 
			$(AR) $(NAME) $(OBJS)

clean:	
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re


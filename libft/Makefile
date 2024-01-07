SRCS	= ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strlen.c \
		  ft_putstr_fd.c

HEAD	= libft.h

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

AR		= ar rc

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME}

all: 		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all

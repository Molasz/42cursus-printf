NAME		= libftprintf.a

HEAD		= ft_printf.h

SRCS		= ft_printf.c ft_putunbr_fd.c ft_puthex_fd.c

OBJS		= ${SRCS:.c=.o}

CC			= cc 

CFLAGS		= -Wall -Wextra -Werror

AR			= ar -rcs

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			make -C libft
			mv libft/libft.a ${NAME}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			make -C libft fclean
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all

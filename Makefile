SRCS		= ft_printf.c ft_putunbr_fd.c

HEAD		= ft_printf.h

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

AR			= ar rc

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

LIBPATH		= libft

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			cd ${LIBPATH} && make re
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			cd ${LIBPATH} && make fclean
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all

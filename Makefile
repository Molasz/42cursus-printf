# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:56:25 by molasz-a          #+#    #+#              #
#    Updated: 2024/01/20 16:23:43 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEAD		= ft_printf.h

LIBFT		= libft/libft.a

SRCS		= ft_printf.c \
			  ft_checks.c \
			  ft_putchr.c \
			  ft_puthex.c \
			  ft_putint.c \
			  ft_putstr.c \
			  ft_putunsign.c \
			  ft_strhex.c \
			  ft_uitoa.c \
			  ft_utils.c

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -f

all:		${NAME}

%.o:		%.c
				${CC} ${CFLAGS} -c $<

#${NAME}:	${LIBFT} ${OBJS} ${HEAD} Makefile
#				cp ${LIBFT} libft/${NAME}
#				mv libft/${NAME} ${NAME}
#				${AR} ${NAME} ${OBJS}

${NAME}:	${LIBFT} ${HEAD} Makefile
				cp ${LIBFT} libft/${NAME}
				mv libft/${NAME} ${NAME}
				cc -c srcs/*.c srcs/*/*.c
				${AR} ${NAME} *.o

${LIBFT}:
				make -C libft

bonus:		${NAME}

clean:
			make -C libft clean
				${RM} ${OBJS} ${DEPS} *.o

fclean:		clean
				${RM} ${TEST}
				${RM} ${LIBFT}
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all

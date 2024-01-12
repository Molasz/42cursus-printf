# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:56:25 by molasz-a          #+#    #+#              #
#    Updated: 2024/01/12 16:43:59 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEAD		= ft_printf.h

SRCS		= ft_printf.c ft_strhex.c ft_uitoa.c checks.c 

OBJS		= ${SRCS:.c=.o}

CC			= cc 

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -f

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< 

${NAME}:	${OBJS}
			make -C libft
			mv libft/libft.a ${NAME}
			${AR} ${NAME} ${OBJS}

clean:
			make -C libft clean
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all

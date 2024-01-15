# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:56:25 by molasz-a          #+#    #+#              #
#    Updated: 2024/01/15 13:02:32 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEAD		= ft_printf.h

MAKE		= Makefile

SRCS		= ft_printf.c \
			  ft_checks.c \
			  ft_formater.c \
			  ft_identifiers.c \
			  ft_strhex.c \
			  ft_uitoa.c \

OBJS		= ${SRCS:.c=.o}

DEPS		= ${SRCS:.c=.d}

CC			= cc 

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -f

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -MMD -MP

${NAME}:	${OBJS} ${HEAD} ${MAKE}
			make -C libft
			mv libft/libft.a ${NAME}
			${AR} ${NAME} ${OBJS}

clean:
			make -C libft clean
			${RM} ${OBJS} ${DEPS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all

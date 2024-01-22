# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:56:25 by molasz-a          #+#    #+#              #
#    Updated: 2024/01/22 09:30:26 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEAD		= ft_printf.h

LIBFT		= libft/libft.a

SRCS		= srcs/ft_printf.c \
				srcs/ft_checks.c \
				srcs/ft_utils.c \
				srcs/putchr/ft_putchr.c \
				srcs/puthex/ft_puthex.c \
				srcs/puthex/ft_puthex_justify.c \
				srcs/puthex/ft_puthex_precision.c \
				srcs/puthex/ft_strhex.c \
				srcs/putint/ft_putint.c \
				srcs/putint/ft_putint_justify.c \
				srcs/putint/ft_putint_precision.c \
				srcs/putstr/ft_putstr.c \
				srcs/putuns/ft_putuns.c \
				srcs/putuns/ft_putuns_precision.c

OBJS		= ft_printf.o \
				ft_checks.o \
				ft_utils.o \
				ft_putchr.o \
				ft_puthex.o \
				ft_puthex_justify.o \
				ft_puthex_precision.o \
				ft_strhex.o \
				ft_putint.o \
				ft_putint_justify.o \
				ft_putint_precision.o \
				ft_putstr.o \
				ft_putuns.o \
				ft_putuns_precision.o

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -f

all:		${NAME}

%.o:		srcs/%.c
				${CC} ${CFLAGS} -c $<

%.o:		srcs/*/%.c
				${CC} ${CFLAGS} -c $<

#${NAME}:	${LIBFT} ${OBJS} ${HEAD} Makefile
#				cp ${LIBFT} libft/${NAME}
#				mv libft/${NAME} ${NAME}
#				${AR} ${NAME} ${OBJS}

${NAME}:	${LIBFT} ${OBJS} ${HEAD} Makefile
				cp ${LIBFT} libft/${NAME}
				mv libft/${NAME} ${NAME}
				${AR} ${NAME} ${OBJS}

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:56:25 by molasz-a          #+#    #+#              #
#    Updated: 2024/01/24 00:37:35 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= libft.a

LIBDIR		= libft

SRCS		= ft_printf.c \
				ft_checks.c \
				ft_utils.c \
				ft_putchr.c \
				ft_puthex.c \
				ft_puthex_justify.c \
				ft_puthex_precision.c \
				ft_strhex.c \
				ft_putint.c \
				ft_putint_justify.c \
				ft_putint_precision.c \
				ft_putstr.c \
				ft_putuns.c \
				ft_putuns_precision.c

OBJS		= ${addprefix ${ODIR}, $(SRCS:.c=.o)}

SDIR		= src/

ODIR		= obj/

DEPS		= ${addprefix ${ODIR}, $(SRCS:.c=.d)}

CFLAGS		= -Wall -Wextra -Werror -MMD

AR			= ar rcs

RM			= rm -rf

all:		dir ${NAME}

dir:
				make -C libft
				mkdir -p ${ODIR}

obj/%.o:	src/%.c Makefile
				${CC} ${CFLAGS} -c $< -o $@ 

${NAME}:	${OBJS}
				cp ${LIBDIR}/${LIBFT} ${LIBDIR}/${NAME}
				mv ${LIBDIR}/${NAME} ${NAME}
				${AR} ${NAME} ${OBJS}

bonus:		all

clean:
				make -C libft clean
				${RM} ${ODIR}

fclean:		
				make -C libft fclean
				${RM} ${ODIR}
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all dir

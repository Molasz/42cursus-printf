# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:56:25 by molasz-a          #+#    #+#              #
#    Updated: 2024/01/23 21:11:39 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

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

LIBFT		= libft/libft.a

DIR			= obj/

OBJS	= ${addprefix ${DIR}, $(SRCS:.c=.o)}

DEPS	= ${addprefix ${DIR}, $(SRCS:.c=.d)}

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -rf

all:		dir ${NAME}

dir:
				mkdir -p ${DIR}
				make -C libft

obj/%.o:	srcs/%.c Makefile ${LIBFT}
				${CC} ${CFLAGS} -MMD -c $< -o $@

${NAME}:	${OBJS}
				cp ${LIBFT} libft/${NAME}
				mv libft/${NAME} ${NAME}
				${AR} ${NAME} ${OBJS}

bonus:		all

clean:
			make -C libft clean
			${RM} ${DIR}

fclean:		clean
				make -C libft fclean
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all dir

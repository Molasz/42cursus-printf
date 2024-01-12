/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/12 19:08:49 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	print_result(char *s, int *flags, int *width)
{
	int		i;
	char	c;
	int		s_len;

	/*
	printf("----------\n");
	printf("s:%s\n", s);
	printf("flags: %d, %d, %d\n", flags[0], flags[1], flags[2]);
	printf("width: %d, %d\n", width[0], width[1]);
	printf("----------\n");
	*/

	i = 0;
	c = ' ';
	s_len = ft_strlen(s);
	if (flags[1])
		s_len++;
	if (flags[0])
	{
		if (flags[0] == 2)
			c = '0';
		if (width[0])
		{
			while (i < width[0] - s_len)
			{
				ft_putchar_fd(c, 1);
				i++;
			}
		}
	}
	if (flags[1] == 1)
		ft_putchar_fd('+', 1);
	else if (flags[1] == 2)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(s, 1);
	if (!width[0])
	{
		while (i < width[0] - s_len)
		{
			ft_putchar_fd(c, 1);
			i++;
		}
	}
}

static int	args_check(char *s, va_list args)
{
	char	*res;
	int		flags[3];
	int		width[2];
	int		i;

	i = 0;
	s++;
	ft_bzero(flags, 3);
	ft_bzero(width, 2);
	while (!ft_strrchr("cspdiuxX%", s[i]))
	{
		flags_check(s[i], flags);
		if (ft_isdigit(s[i]))
		{
			i += width_check(&s[i], width);
			break ;
		}
		i++;
	}
	if (!s[i])
		return (1);
	res = identifiers_check(s[i], args);
	print_result(res, flags, width);
	free(res);
	return (i + 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			i += args_check(&((char *)s)[i], args);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/10 01:19:08 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_args(char *s)
{
	int	i;

	i = 0;
	while (!ft_strrchr("cspduxX%", s[i]))
	{
		if (s[i] == '-')
			ft_putchar_fd('-', 1);
		else if (s[i] == '0')
			ft_putchar_fd('0', 1);
		else if (s[i] == '.')
			ft_putchar_fd('.', 1);
		else if (s[i] == '#')
			ft_putchar_fd('#', 1);
		else if (s[i] == ' ')
			ft_putchar_fd(' ', 1);
		else if (s[i] == '+')
			ft_putchar_fd('+', 1);
		else
			ft_putstr_fd("ERROR", 1);
		i++;
	}
	return (i);
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
			check_args(&((char *)s)[i]);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (0);
}

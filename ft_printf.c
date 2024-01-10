/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/10 15:56:17 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flags_check(char c, va_list args)
{
	char	*s;
	if (c == 'c')
		va_arg(args, int);
	else if (c == 's')
		s = va_arg(args, char *);
	else if (c == 'p')
		ft_putp_fd(va_arg(args, void *), 1);
	else if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_puthexl_fd(va_arg(args, unsigned long), 1);
	else if (c == 'X')
		ft_puthexu_fd(va_arg(args, unsigned long), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

static int	check_args(char *s, va_list args)
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
	if (!s[i])
		flags_check(s[i], args);
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
			check_args(&((char *)s)[i], args);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:48:01 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 14:28:22 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags_check(char c, int *flags)
{
	if (flags[0] != 1)
	{
		if (c == '-')
			flags[0] = 1;
		else if (c == '0')
			flags[0] = 2;
	}
	if (flags[1] != '+' && (c == '+' || c == ' '))
		flags[1] = c;
	if (c == '#')
		flags[2] = 1;
	else if (c == '.')
		flags[4] = 0;
}

static int	ft_width_check(char *s, int *flags)
{
	int	num;
	int	i;

	i = 0;
	num = ft_atoi(s);
	if (flags[3])
		flags[4] = num;
	else
		flags[3] = num;
	while (ft_isdigit(s[i]))
		i++;
	return (i - 1);
}

int	ft_identifiers(char c, va_list args, int *flags)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len = ft_putint(va_arg(args, int), flags);
	else if (c == 'u')
		len = ft_putunsign(va_arg(args, unsigned int), flags);
	else if (c == 'x' || c == 'X')
		len = ft_puthex(va_arg(args, unsigned int), flags, c == 'x', 0);
	else if (c == 'p')
		len = ft_puthex((unsigned long)va_arg(args, void *), flags, 1, 1) + 2;
	else if (c == 'c')
		len = ft_putchr(va_arg(args, int), flags);
	else if (c == '%')
		len = ft_putchr('%', flags);
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *), flags);
	return (len);
}

/*
 * FLAGS
 * 0: Justify char	1:Left justify , 2:Justify with 0
 * 1: Number sign	1:'+' , 2:' '
 * 2: 0x on hex		1:0x Prefix
 * 3: Width
 * 4: Precision
 */
int	ft_check_args(char *s, va_list args)
{
	int		*flags;
	int		i;

	i = 0;
	flags = ft_calloc(sizeof (int), 5);
	if (!flags)
		return (-1);
	flags[4] = -1;
	while (!ft_strrchr("cspdiuxX%", s[i]))
	{
		ft_flags_check(s[i], flags);
		if (ft_isdigit(s[i]))
			i += ft_width_check(&s[i], flags);
		i++;
	}
	i = ft_identifiers(s[i], args, flags);
	free(flags);
	return (i);
}
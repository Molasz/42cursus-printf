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

static int	ft_flags_check(char *s, t_flags *flags)
{
	int	i;

	if ( (*s == '-' || *s == '0') && flags->justify != '-')
		flags->justify = *s;
	else if ((*s == '+' || *s == ' ') && flags->sign != '+')
		flags->sign = *s;
	else if (*s == '#')
		flags->prefix = 1;
	else if (*s == '.')
		flags->precision = 0;
	else if (*s > '0' && *s <= '9')
	{
		i = 0;
		if (flags->len)
			flags->precision = (size_t)ft_atoi(s);
		else
			flags->len = (size_t)ft_atoi(s);
		while (ft_isdigit(s[i]))
			i++;
		return (i - 1);
	}
	return (1);
}

int	ft_identifiers(char c, va_list args, t_flags *flags)
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

int	ft_check_args(char *s, va_list args)
{
	t_flags	*flags;
	int		i;

	i = 0;
	flags = malloc(sizeof (t_flags));
	if (!flags)
		return (-1);
	flags->justify = 0;
	flags->sign = 0;
	flags->prefix = 0;
	flags->len = 0;
	flags->precision = -1;
	while (!ft_strrchr("cspdiuxX%", s[i]))
		ft_flags_check(s + i, flags);
	i = ft_identifiers(s[i], args, flags);
	free(flags);
	return (i);
}
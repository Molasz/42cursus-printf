/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:48:01 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/15 00:39:40 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_check(char c, int *flags)
{
	if (flags[0] != 1)
	{
		if (c == '-')
			flags[0] = 1;
		else if (c == '0')
			flags[0] = 2;
	}
	if (flags[1] != '+')
	{
		if (c == '+' || c == ' ')
			flags[1] = c;
	}
	if (c == '#')
		flags[2] = 1;
}

int	width_check(char *c, int *flags)
{
	int	i;

	i = 0;
	flags[3] = ft_atoi(c);
	while (ft_isdigit(c[i]))
		i++;
	if (c[i] != '.')
		return (i);
	flags[4] = ft_atoi(c + 1);
	while (ft_isdigit(c[i]))
		i++;
	return (i);
}

char	*identifiers_check(char c, va_list args, int *flags)
{
	char	*s;
	char	v;
	int		n;

	s = NULL;
	n = 0;
	v = '%';
	if (c == 'c' || c == '%')
	{
		if (c == 'c')
			v = va_arg(args, int);
		s = ft_substr(&v, 0, 1);
	}
	else if (c == 's')
		s = ft_substr(va_arg(args, char*), 0, ft_strlen(s));
	else if (c == 'd' || c == 'i')
	{
		n = va_arg(args, int);
		s = ft_itoa(n);
	}
	else if (c == 'u')
		s = ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		s = ft_strhex(va_arg(args, unsigned long), c == 'x');
	else if (c == 'p')
		s = ft_strp(va_arg(args, void *));

	ft_hexprefix(c, s, flags[2]);
	ft_add_sign(c , s, flags[1]);
	ft_justify(s, flags[0], flags[3]);
	return (s);
}

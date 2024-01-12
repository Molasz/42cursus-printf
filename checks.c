/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:48:01 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/12 19:09:01 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_check(char c, int flags[3])
{
	if (flags[0] != 1)
	{
		if (c == '-')
			flags[0] = 1;
		else if (c == '0')
			flags[0] = 2;
	}
	if (flags[1] != 1)
	{
		if (c == '+')
			flags[1] = 1;
		else if (c == ' ')
			flags[1] = 2;
	}
	if (c == '#')
		flags[2] = 1;
}

int	width_check(char *c, int *nbr)
{
	int	i;

	i = 0;
	nbr[0] = ft_atoi(c);
	while (ft_isdigit(c[i]))
		i++;
	if (c[i] != '.')
		return (i);
	nbr[1] = ft_atoi(c + 1);
	while (ft_isdigit(c[i]))
		i++;
	return (i);
}

char	*identifiers_check(char c, va_list args)
{
	char	*s;

	s = NULL;
	if (c == 'c' || c == '%')
	{
		if (c == 'c')
			c = va_arg(args, int);
		s = ft_substr(&c, 0, 1);
	}
	else if (c == 's')
	{
		s = va_arg(args, char *);
		s = ft_substr(s, 0, ft_strlen(s));
	}
	else if (c == 'p')
		s = ft_strp(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		s = ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		s = ft_strhex(va_arg(args, unsigned long), c == 'x');
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:48:01 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/15 19:34:25 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * FLAGS[5]
 * 0: Justify char	1:Left justify , 2:Left justify with 0
 * 1: Number sign	1:'+' , 2:' '
 * 2: 0x on hex
 * 3: len min
 * 4: len max
 */
char	*args_check(char *s, va_list args)
{
	char	*res;
	int		*flags;
	int		i;

	i = 0;
	flags = ft_calloc(sizeof (int), 5);
	if (!flags)
		return (NULL);
	while (!ft_strrchr("cspdiuxX%", s[i]))
	{
		flags_check(s[i], flags);
		if (ft_isdigit(s[i]))
		{
			i += width_check(&s[i], flags);
			break ;
		}
		i++;
	}
	res = ft_identifiers_check(s[i], args, flags);
	if (!res)
		return (NULL);
	free(flags);
	return (res);
}

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

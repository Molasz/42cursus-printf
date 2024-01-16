/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:48:01 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 12:38:42 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * FLAGS[5]
 * 0: Justify char	1:Left justify , 2:Left justify with 0
 * 1: Number sign	1:'+' , 2:' '
 * 2: 0x on hex		1:'#'
 * 3: Precision     1:'.'
 * 4: len min
 * 5: len max
 */
char	*args_check(char *s, va_list args)
{
	char	*res;
	int		*flags;
	int		i;

	i = 0;
	flags = ft_calloc(sizeof (int), 6);
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
	if (flags[1] != '+' && (c == '+' || c == ' '))
		flags[1] = c;
	if (c == '#')
		flags[2] = 1;
	else if (c == '.')
		flags[3] = 1;
}

int	width_check(char *s, int *flags)
{
	int	num;
	int	i;

	i = 0;
	num = ft_atoi(s);
	if (flags[3])
		flags[5] = num;
	else
		flags[4] = num;
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

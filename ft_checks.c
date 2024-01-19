/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:48:01 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/18 13:16:25 by molasz-a         ###   ########.fr       */
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
	{
		if (flags[3] < 0)
			flags[3] = 0; 
		flags[4] = 0;
	}
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

/*
 * FLAGS[5]
 * 0: Justify char	1:Left justify , 2:Justify with 0
 * 1: Number sign	1:'+' , 2:' '
 * 2: 0x on hex		1:'#'
 * 3: Precision     1:'.'
 * 4: len min
 * 5: len max
 */
int	ft_check_args(char *s, va_list args)
{
	int		*flags;
	int		i;

	i = 0;
	flags = ft_calloc(sizeof (int), 6);
	if (!flags)
		return (-1);
	flags[4] = -1;
	flags[5] = -1;
	while (!ft_strrchr("cspdiuxX%", s[i]))
	{
		ft_flags_check(s[i], flags);
		if (ft_isdigit(s[i]))
			i += ft_width_check(&s[i], flags);
		i++;
	}
	i = ft_check_identifiers(s[i], args, flags);
	free(flags);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:13:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/15 01:01:52 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
 * FLAGS[5]
 * 0: Justify char	1:' ' , 2:'0'
 * 1: Number sign	1:'+' , 2:' '
 * 2: 0x on hex
 * 3: len min
 * 4: len max
 */
static char	*args_check(char *s, va_list args)
{
	char	*res;
	int		*flags;
	int		i;

	i = 0;
	s++;
	flags = ft_calloc(sizeof (int), 5);
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
	res = identifiers_check(s[i], args, flags);
	ft_addsign(s[i], res, flags[1]);
	ft_justify(res, flags[0], flags[3]);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char	*res;
	char	*tmp;
	char	*res_tmp;
	int		last_i;
	int		i;

	i = 0;
	last_i = 0;
	res = NULL;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			res_tmp = res;
			tmp = ft_substr(s, last_i, last_i - i);
			if (!tmp)
				return (0);
			res = ft_strjoin(res_tmp, tmp);
			if (!res)
				return (0);
			free(tmp);
			free(res_tmp);
			tmp = args_check(&((char *)s)[i], args);
			while (!ft_strrchr("cspdiuxX%", s[i]))
				i++;
			last_i = ++i;
			res_tmp = res;
			res = ft_strjoin(res_tmp, tmp);
			free(tmp);
			free(res_tmp);
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	ft_putstr_fd(res, 1);
	return (ft_strlen(res));
}

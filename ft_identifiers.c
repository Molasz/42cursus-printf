/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:52:11 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/15 19:54:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_emptystr(void)
{
	char	*s;

	s = ft_calloc(sizeof(char), 1);
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}

char	*ft_identifiers_check(char c, va_list args, int *flags)
{
	char			*res;
	char			chr;
	int				num;
	unsigned long	lnum;

	num = -1;
	lnum = -1;
	res = NULL;
	chr = '%';
	if (c == 'c' || c == '%')
	{
		if (c == 'c')
			chr = va_arg(args, int);
		if (chr)
			res = ft_chrstr(chr);
		else
			res = ft_emptystr();
	}
	else if (c == 's')
	{
		res = va_arg(args, char *);
		res = ft_substr(res,  0, ft_strlen(res));
	}
	else if (c == 'd' || c == 'i')
	{
		num = va_arg(args, int);
		res = ft_itoa(num);
	}
	else if (c == 'u')
		res = ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		res = ft_strhex(va_arg(args, unsigned int), c == 'x', flags[2]);
	else if (c == 'p')
		res = ft_strp(va_arg(args, void *));
	if (num >= 0 || lnum >= 0)
	{
		res = ft_addsign(c, res, flags[1]);
		if (!res)
			return (NULL);
	}
	res = ft_justify(res, flags[0], flags[3]);
	if (!res)
		return (NULL);
	return (res);
}

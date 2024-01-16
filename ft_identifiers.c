/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:52:11 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/16 12:42:56 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chrstr(char c)
{
	char	*s;

	s = ft_calloc(sizeof (char), 2);
	if (!s)
		return (NULL);
	s[0] = c;
	return (s);
}

static char	*ft_identifiers_check_numbers(char c, va_list args, int *n, int *f)
{
	char	*res;

	res = NULL;
	if (c == 'd' || c == 'i')
	{
		*n = va_arg(args, int);
		res = ft_itoa(*n);
	}
	else if (c == 'u')
		res = ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		res = ft_strhex(va_arg(args, unsigned int), c == 'x', f[2]);
	else if (c == 'p')
		res = ft_strp(va_arg(args, void *));
	return (res);
}

static char	*ft_identifiers_check_chars(char c, va_list args)
{
	char	*res;

	res = NULL;
	if (c == 'c')
		res = ft_chrstr(va_arg(args, int));
	else if (c == '%')
		res = ft_chrstr('%');
	else if (c == 's')
	{
		res = va_arg(args, char *);
		res = ft_substr(res, 0, ft_strlen(res));
	}
	return (res);
}

char	*ft_identifiers_check(char c, va_list args, int *flags)
{
	char	*res;
	int		num;

	num = -1;
	res = ft_identifiers_check_numbers(c, args, &num, flags);
	if (!res)
		res = ft_identifiers_check_chars(c, args);
	if (!res)
		return (NULL);
	if (num >= 0)
	{
		res = ft_addsign(c, res, flags[1]);
		if (!res)
			return (NULL);
	}
	if (c != '%')
		res = ft_justify(c, res, flags);
	if (!res)
		return (NULL);
	return (res);
}

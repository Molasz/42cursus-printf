/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:52:11 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/18 15:05:37 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_identifiers_check_numbers(char c, va_list args, int *n)
{
	unsigned int	p;
	char			*res;

	res = NULL;
	if (c == 'd' || c == 'i')
	{
		*n = va_arg(args, int);
		res = ft_uitoa(ft_abs(*n));
	}
	else if (c == 'u')
		res = ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
	{
		p = va_arg(args, unsigned int);
		*n = p > 0;
		res = ft_strhex(p, c == 'x');
	}
	else if (c == 'p')
		res = ft_strp(va_arg(args, void *));
	return (res);
}

static char	*ft_identifiers_check_chars(char c, va_list args, int *flags)
{
	char	*str;
	char	*res;

	res = NULL;
	if (c == 'c')
		res = ft_chrstr(va_arg(args, int));
	else if (c == '%')
		res = ft_chrstr('%');
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (str)
			res = ft_substr(str, 0, ft_strlen(str));
		else
			res = ft_substr("(null)", 0, 6);
		return (ft_putstr(res, flags));
	}
	return (res);
}

int	ft_check_identifiers(char c, va_list args, int *flags)
{
	char	*res;
	int		extra_len;
	int		num;

	num = -1;
	extra_len = 0;
	res = ft_identifiers_check_numbers(c, args, &num);
	if (!res)
		res = ft_identifiers_check_chars(c, args, flags);
	if (!res)
		return (-1);
	if (c == 'c' && !ft_strlen(res))
	{
		if (write(1, res, 1) < 0)
		{
			free(res);
			return (-1);
		}
		extra_len++;
	}
	/*
	if (flags[3] || flags[4] != -1 || flags[5] != -1 || num != 0)
		res = ft_format(c, res, flags, num);
	if (!res)
		return (-1);
	num = ft_strlen(res);
	if (write(1, res, num) < 0)
	{
		free(res);
		return (-1);
	}
	free(res);
	*/
	return (num + extra_len);
}

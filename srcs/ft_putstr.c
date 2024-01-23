/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:22:45 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/23 16:13:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_putstr_prec(char *arg, char *res, t_flags *flags, size_t *len)
{
	char	*str;

	str = ft_substr(res, 0, flags->precision);
	if (!arg)
		free(res);
	if (!str)
		return (NULL);
	*len = flags->precision;
	return (str);
}

static int	ft_putstr_justify(char *res, t_flags *flags, size_t len)
{
	if (flags->justify == '0')
	{
		if (ft_putjustify('0', flags->len - len) < 0)
			return (-1);
		if (write(1, res, len) < 0)
			return (-1);
	}
	if (flags->justify == '-')
	{
		if (write(1, res, len) < 0)
			return (-1);
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
	}
	else
	{
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
		if (write(1, res, len) < 0)
			return (-1);
	}
	return (flags->len);
}

int	ft_writestr(char *str, t_flags *flags, size_t len)
{
	int	write_len;

	write_len = 0;
	if (flags->len > len)
		write_len = ft_putstr_justify(str, flags, len);
	else
		write_len = write(1, str, len);
	return (write_len);
}

int	ft_putstr(char *arg, t_flags *flags)
{
	int		write_len;
	char	*res;
	size_t	len;

	res = arg;
	if (!arg)
	{
		res = ft_substr("(null)", 0, 6);
		if (!res)
			return (-1);
	}
	len = ft_strlen(res);
	if (flags->has_precision && flags->precision <= len)
	{
		res = ft_putstr_prec(arg, res, flags, &len);
		if (!res)
			return (-1);
	}
	write_len = ft_writestr(res, flags, len);
	if ((flags->has_precision && flags->precision == len) || !arg)
		free(res);
	return (write_len);
}

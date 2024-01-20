/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:55:33 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 18:39:05 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_justify(char *arg, t_flags *flags, size_t len)
{
	int	write_len;

	if (flags->justify == '0')
	{
		write_len = ft_putjustify('0', flags->len - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, arg, len);
	}
	if (flags->justify == '-')
	{
		write_len = write(1, arg, len);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify(' ', flags->len - len);
	}
	else
	{
		write_len = ft_putjustify(' ', flags->len - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, arg, len);
	}
	if (write_len < 0)
		return (-1);
	return (flags->len);
}

int	ft_putstr(char *arg, t_flags *flags)
{
	char	*res;
	size_t	len;
	int		write_len;

	res = arg;
	if (!arg)
	{
		res = ft_substr("(null)", 0, 6);
		if (!res)
			return (-1);
	}
	len = ft_strlen(res);
	if (flags->precision && flags->precision < len)
	{
		if (res != arg)
			free(res);
		res = ft_substr(res, 0, flags->precision);
		if (!res)
			return (-1);
	}
	if (flags->len >= len)
		write_len = ft_putstr_justify(res, flags, len);
	else
		write_len = write(1, res, len);
	if (res != arg)
		free(res);
	return (write_len);
}

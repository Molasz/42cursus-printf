/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:06 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/20 16:47:30 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_pre(int prefix, int lower)
{
	if (prefix)
	{
		if (lower)
			return (write(1, "0x", 2));
		else
			return (write(1, "0X", 2));
	}
	return (0);
}

static int	ft_puthex_precision(char *hex, t_flags *flags, int pre, int lower)
{
	int		sign_len;
	size_t	len;

	len = ft_strlen(hex);
	sign_len = 0;
	if (pre)
		sign_len = 2;
	if (flags->justify == '0')
	{
		if (ft_puthex_pre(pre, lower) < 0)
			return (-1);
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (-1);
		if (flags->len > flags->precision)
		{
			if (ft_putjustify('0', flags->len - flags->precision) < 0)
				return (-1);
		}
		if(write(1, hex, len) < 0)
			return (-1);
	}
	else if (flags->justify == '-')
	{
		if (ft_puthex_pre(pre, lower) < 0)
			return (-1);
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (-1);
		if(write(1, hex, len) < 0)
			return (-1);
		if (flags->len > flags->precision)
		{
			if (ft_putjustify(' ', flags->len - flags->precision) < 0)
				return (-1);
		}
	}
	else
	{
		if (flags->len > flags->precision)
		{
			if (ft_putjustify(' ', flags->len - flags->precision) < 0)
				return (-1);
		}
		if (ft_puthex_pre(pre, lower) < 0)
			return (-1);
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (-1);
		if(write(1, hex, len) < 0)
			return (-1);
	}
	if (flags->len + sign_len > flags->precision)
		return (flags->len + sign_len);
	return (flags->precision + len);
}

static int	ft_puthex_justify(char *hex, t_flags *flags, int pre, int lower)
{
	size_t	len;

	len = ft_strlen(hex);
	if (flags->justify == '0')
	{
		if (ft_puthex_pre(pre, lower) < 0)
			return (-1);
		if (ft_putjustify('0', flags->len - len) < 0)
			return (-1);
		if (write(1, hex, len) < 0)
			return (-1);
	}
	else if (flags->justify == '-')
	{
		if (ft_puthex_pre(pre, lower) < 0)
			return (-1);
		if (write(1, hex, len) < 0)
			return (-1);
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
	}
	else
	{
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
		if (ft_puthex_pre(pre, lower) < 0)
			return (-1);
		if (write(1, hex, len) < 0)
			return (-1);
	}
	if (pre)
		flags->len += 2;
	return (flags->len);
}

int	ft_puthex(unsigned long arg, t_flags *flags, int lower, int p)
{
	char	*hex;
	size_t	len;
	int		write_len;
	int		prefix;

	hex = ft_strhex(arg, lower);
	if (!hex)
		return (-1);
	len = ft_strlen(hex);
	write_len = 0;
	prefix = (flags->prefix && arg) || p;
	if (flags->len && prefix)
		flags->len -= 2;
	if (flags->precision > len)
		write_len = ft_puthex_precision(hex, flags, prefix, lower);
	else if (flags->len > len)
		write_len = ft_puthex_justify(hex, flags, prefix, lower);
	else
	{
		write_len = ft_puthex_pre(prefix, lower);
		if (write_len < 0)
		{
			free(hex);
			return (-1);
		}
		write_len = write(1, hex, ft_strlen(hex));
		if (write_len < 0)
			return (-1);
		if (prefix)
			write_len += 2;
	}
	free(hex);
	if (write_len < 0)
		return (-1);
	return (write_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:06 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 18:53:30 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_pre(int lower)
{
	if (lower)
		return (write(1, "0x", 2));
	else
		return (write(1, "0X", 2));
}

static int	ft_puthex_precision(char *hex, t_flags *flags, int pre, int lower)
{
	int		write_len;
	size_t	len;

	len = ft_strlen(hex);
	if (flags->justify == '0')
	{
		if (pre)
			write_len = ft_puthex_pre(lower);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		if (flags->len > flags->precision + len)
			write_len = ft_putjustify('0', flags->len - flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, hex, len);
	}
	else if (flags->justify == '-')
	{
		if (pre)
			write_len = ft_puthex_pre(lower);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, hex, len);
		if (write_len < 0)
			return (-1);
		if (flags->len > flags->precision + len)
			write_len = ft_putjustify(' ', flags->len - flags->precision - len);
	}
	else
	{
		if (flags->len > flags->precision + len)
			write_len = ft_putjustify(' ', flags->len - flags->precision + len);
		if (write_len < 0)
			return (-1);
		if (pre)
			write_len = ft_puthex_pre(lower);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, hex, len);
	}
	if (write_len < 0)
		return (-1);
	if (flags->len)
		return (flags->len);
	return (len + flags->precision);
}

static int	ft_puthex_justify(char *hex, t_flags *flags, int pre, int lower)
{
	int		write_len;
	size_t	len;

	len = ft_strlen(hex);
	if (flags->justify == '0')
	{
		if (pre)
			write_len = ft_puthex_pre(lower);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->len - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, hex, len);
	}
	else if (flags->justify == ' ')
	{
		if (pre)
			write_len = ft_puthex_pre(lower);
		if (write_len < 0)
			return (-1);
		len = write(1, hex, len);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify(' ', flags->len - len);
	}
	else
	{
		write_len = ft_putjustify(' ', flags->len - len);
		if (write_len < 0)
			return (-1);
		if (pre)
			write_len = ft_puthex_pre(lower);
		if (write_len < 0)
			return (-1);
		write_len = write(1, hex, len);
	}
	return (flags->len);
}

int	ft_puthex(unsigned long arg, t_flags *flags, int lower, int p)
{
	char	*hex;
	size_t	len;
	int		write_len;

	hex = ft_strhex(arg, lower);
	if (!hex)
		return (-1);
	len = ft_strlen(hex);
	write_len = 0;
	if (flags->precision > len)
		write_len = ft_puthex_precision(hex, flags, (flags->prefix && !arg) || p, lower);
	else if (flags->len > len)
		write_len = ft_puthex_justify(hex, flags, (flags->prefix && !arg) || p, lower);
	else
	{
		if ((flags->prefix && arg) || p)
			write_len = ft_puthex_pre(lower);
		if (write_len < 0)
		{
			free(hex);
			return (-1);
		}
		write_len = write(1, hex, ft_strlen(hex));
	}
	free(hex);
	if (write_len < 0)
		return (-1);
	if ((flags->prefix && arg) || p)
		write_len += 2;
	return (write_len);
}

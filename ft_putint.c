/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:59:47 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 19:11:04 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putint_pre(int num, int sign)
{
	if (num < 0)
		return (write(1, "-", 1));
	else if (sign)
		return (write(1, &sign, 1));
	return (0);
}

static int	ft_putint_precision(char *num, t_flags *flags, int n, size_t len)
{
	int	write_len;
	int	sign_len;

	write_len = 0;
	sign_len = 0;
	if (flags->justify == '0')
	{
		if (flags->sign || n < 0)
			write_len = ft_putint_pre(n, flags->sign);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		if (flags->len > flags->precision + len)
			write_len = ft_putjustify('0', flags->len - flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, num, len);
	}
	else if (flags->justify == '-')
	{
		if (flags->sign || n < 0)
			write_len = ft_putint_pre(n, flags->sign);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, num, len);
		if (write_len < 0)
			return (-1);
		if (flags->len > flags->precision + len)
			write_len = ft_putjustify(' ', flags->len - flags->precision - len);
	}
	else
	{
		if (flags->len > flags->precision)
			write_len = ft_putjustify(' ', flags->len - flags->precision);
		if (write_len < 0)
			return (-1);
		if (flags->sign || n < 0)
			write_len = ft_putint_pre(n, flags->sign);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, num, len);
	}
	if (write_len < 0)
		return (-1);
	if (n < 0 || flags->sign)
		sign_len = 1;
	if (flags->len + sign_len > flags->precision)
		return (flags->len + sign_len);
	return (flags->precision + sign_len);
}

static int	ft_putint_justify(char *num, t_flags *flags, int n, size_t len)
{
	int	write_len;

	write_len = 0;
	if (flags->justify == '0')
	{
		if (flags->sign || n < 0)
			write_len = ft_putint_pre(n, flags->sign);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->len - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, num, len);
	}
	else if (flags->justify == '-')
	{
		if (flags->sign || n < 0)
			write_len = ft_putint_pre(n, flags->sign);
		if (write_len < 0)
			return (-1);
		write_len = write(1, num, len);
		if (write_len < 0)
			return (-1);
		if (flags->len > len)
			write_len = ft_putjustify(' ', flags->len - len);
	}
	else
	{
		if (flags->len > len)
			write_len = ft_putjustify(' ', flags->len - len);
		if (write_len < 0)
			return (-1);
		if (flags->sign || n < 0)
			write_len = ft_putint_pre(n, flags->sign);
		if (write_len < 0)
			return (-1);
		write_len = write(1, num, len);
	}
	if (write_len < 0)
			return (-1);
	if (flags->sign || n < 0)
		flags->len++;
	return (flags->len);
}

int	ft_putint(int arg, t_flags *flags)
{
	char	*num;
	size_t	len;
	int		write_len;

	len = 0;
	num = ft_uitoa(ft_abs(arg));
	write_len = 0;
	if (!num)
		return (-1);
	len = ft_strlen(num);
	if (flags->len && (arg < 0 || flags->sign))
		flags->len--;
	if (flags->precision > len)
		write_len = ft_putint_precision(num, flags, arg, len);
	else if (flags-> len > len)
		write_len = ft_putint_justify(num, flags, arg, len);
	else
	{
		if (flags->sign || arg < 0)
			write_len = ft_putint_pre(arg, flags->sign);
		if (write_len < 0)
		{
			free(num);
			return (-1);
		}
		write_len = write(1, num, ft_strlen(num));
		if (arg < 0 || flags->sign)
			write_len++;
	}
	free(num);
	if (write_len < 0)
		return (-1);
	return (write_len);
}

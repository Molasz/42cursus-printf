/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:26:04 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/23 16:13:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_puthex_prec_zero(char *hex, t_flags *flags,	int pre, int lower)
{
	size_t	len;
	int		space_len;

	len = ft_strlen(hex);
	space_len = flags->len - len;
	if (flags->precision > len)
		space_len = flags->len - flags->precision;
	if (flags->len > flags->precision && space_len > 0)
	{
		if (ft_putjustify(' ', space_len) < 0)
			return (1);
	}
	if (ft_puthex_pre(pre, lower) < 0)
		return (1);
	if (flags->precision > len)
	{
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (1);
	}
	if (write(1, hex, len) < 0)
		return (1);
	return (0);
}

static int	ft_puthex_prec_left(char *hex, t_flags *flags, int pre, int lower)
{
	size_t	len;
	int		space_len;

	len = ft_strlen(hex);
	space_len = flags->len - len;
	if (flags->precision > len)
		space_len = flags->len - flags->precision;
	if (ft_puthex_pre(pre, lower) < 0)
		return (1);
	if (flags->precision > len)
	{
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (1);
	}
	if (write(1, hex, len) < 0)
		return (1);
	if (flags->len > flags->precision && space_len > 0)
	{
		if (ft_putjustify(' ', space_len) < 0)
			return (1);
	}
	return (0);
}

static int	ft_puthex_prec_space(char *hex, t_flags *flags,	int pre, int lower)
{
	size_t	len;
	int		space_len;

	len = ft_strlen(hex);
	space_len = flags->len - len;
	if (flags->precision > len)
		space_len = flags->len - flags->precision;
	if (flags->len > flags->precision && space_len > 0)
	{
		if (ft_putjustify(' ', space_len) < 0)
			return (1);
	}
	if (ft_puthex_pre(pre, lower) < 0)
		return (1);
	if (flags->precision > len)
	{
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (1);
	}
	if (write(1, hex, len) < 0)
		return (1);
	return (0);
}

int	ft_puthex_precision(char *hex, t_flags *flags, int pre, int lower)
{
	int		error;
	int		sign_len;
	size_t	len;

	sign_len = 0;
	len = ft_strlen(hex);
	if (pre)
		sign_len = 2;
	if (flags->justify == '0')
		error = ft_puthex_prec_zero(hex, flags, pre, lower);
	else if (flags->justify == '-')
		error = ft_puthex_prec_left(hex, flags, pre, lower);
	else
		error = ft_puthex_prec_space(hex, flags, pre, lower);
	if (error)
		return (-1);
	if (flags->len < len && flags->precision < len)
		return (len + sign_len);
	if (flags->precision > flags->len)
		return (flags->precision + sign_len);
	else
		return (flags->len + sign_len);
}

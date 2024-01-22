/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:07:55 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/22 09:40:11 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_putint_prec_zero(char *num, t_flags *flags, int n, size_t len)
{
	int	space_len;

	space_len = flags->len - len;
	if (flags->precision > len)
		space_len = flags->len - flags->precision;
	if (flags->len > flags->precision && space_len > 0)
	{
		if (ft_putjustify(' ', space_len) < 0)
			return (1);
	}
	if (ft_putint_pre(n, flags->sign) < 0)
		return (1);
	if (flags->precision > len)
	{
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (1);
	}
	if (write(1, num, len) < 0)
		return (1);
	return (0);
}

static int	ft_putint_prec_left(char *num, t_flags *flags, int n, size_t len)
{
	int	space_len;

	space_len = flags->len - len;
	if (flags->precision > len)
		space_len = flags->len - flags->precision;
	if (ft_putint_pre(n, flags->sign) < 0)
		return (1);
	if (flags->precision > len)
	{
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (1);
	}
	if (write(1, num, len) < 0)
		return (1);
	if (flags->len > flags->precision && space_len > 0)
	{
		if (ft_putjustify(' ', space_len) < 0)
			return (1);
	}
	return (0);
}

static int	ft_putint_prec_normal(char *num, t_flags *flags, int n, size_t len)
{
	int	space_len;

	space_len = flags->len - len;
	if (flags->precision > len)
		space_len = flags->len - flags->precision;
	if (flags->len > flags->precision && space_len > 0)
	{
		if (ft_putjustify(' ', space_len) < 0)
			return (1);
	}
	if (ft_putint_pre(n, flags->sign) < 0)
		return (1);
	if (flags->precision > len)
	{
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (1);
	}
	if (write(1, num, len) < 0)
		return (1);
	return (0);
}

int	ft_putint_precision(char *num, t_flags *flags, int n, size_t len)
{
	int	error;
	int	sign_len;

	sign_len = 0;
	if (n < 0 || flags->sign)
		sign_len = 1;
	if (flags->justify == '0')
		error = ft_putint_prec_zero(num, flags, n, len);
	else if (flags->justify == '-')
		error = ft_putint_prec_left(num, flags, n, len);
	else
		error = ft_putint_prec_normal(num, flags, n, len);
	if (error)
		return (-1);
	if (flags->len > 0 && len > flags->len)
		return (len + sign_len);
	else if (flags->len + sign_len > flags->precision)
		return (flags->len + sign_len);
	else if (flags->precision > len)
		return (flags->precision + sign_len);
	return (len + sign_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:15:10 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/21 20:15:14 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_putunsign_precision_zero(char *arg, t_flags *flags, size_t len)
{
	if (flags->precision > len)
	{
		if (ft_putjustify(' ', flags->precision - len) < 0)
			return (1);
	}
	if (flags->len > flags->precision)
	{
		if (ft_putjustify('0', flags->len - flags->precision) < 0)
			return (1);
	}
	if (write(1, arg, len) < 0)
		return (1);
	return (0);
}

static int	ft_putunsign_precision_left(char *arg, t_flags *flags, size_t len)
{
	if (flags->precision > len)
	{
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (1);
	}
	if (write(1, arg, len) < 0)
		return (1);
	if (flags->len > flags->precision)
	{
		if (ft_putjustify(' ', flags->len - flags->precision) < 0)
			return (1);
	}
	return (0);
}

static int	ft_putunsign_precision_normal(char *arg, t_flags *flags, size_t len)
{
	if (flags->len > flags->precision)
	{
		if (ft_putjustify(' ', flags->len - flags->precision) < 0)
			return (1);
	}
	if (flags->precision > len)
	{
		if (ft_putjustify('0', flags->precision - len) < 0)
			return (1);
	}
	if (write(1, arg, len) < 0)
		return (1);
	return (0);
}

int	ft_putunsign_precision(char *arg, t_flags *flags, size_t len)
{
	if (flags->justify == '0')
	{
		if (ft_putunsign_precision_zero(arg, flags, len))
			return (-1);
	}
	else if (flags->justify == '-')
	{
		if (ft_putunsign_precision_left(arg, flags, len))
			return (-1);
	}
	else if (ft_putunsign_precision_normal(arg, flags, len))
		return (-1);
	if (flags->len > flags->precision)
		return (flags->len);
	else if (flags->precision > len)
		return (flags->precision);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:59:47 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/20 20:11:51 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_putint_pre(int num, int sign)
{
	if (num < 0)
		return (write(1, "-", 1));
	else if (sign)
		return (write(1, &sign, 1));
	return (0);
}

static int	ft_putint_normal(char *num, t_flags *flags, int arg, size_t len)
{
	int	sign;

	sign = 0;
	if (arg < 0 || flags->sign)
		sign = 1;
	if (flags->sign || arg < 0)
	{
		if (ft_putint_pre(arg, flags->sign) < 0)
		{
			free(num);
			return (-1);
		}
	}
	if (write(1, num, ft_strlen(num)) < 0)
		return (-1);
	return (len + sign);
}

int	ft_putint(int arg, t_flags *flags)
{
	char	*num;
	size_t	len;
	int		write_len;

	num = ft_uitoa(ft_abs(arg));
	if (!num)
		return (-1);
	len = ft_strlen(num);
	write_len = 0;
	if (flags->len && (arg < 0 || flags->sign))
		flags->len--;
	if (flags->precision > len)
		write_len = ft_putint_precision(num, flags, arg, len);
	else if (flags-> len > len)
		write_len = ft_putint_justify(num, flags, arg, len);
	else
		write_len = ft_putint_normal(num, flags, arg, len);
	free(num);
	if (write_len < 0)
		return (-1);
	return (write_len);
}

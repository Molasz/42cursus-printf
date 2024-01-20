/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:01:41 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/20 15:51:26 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunsign_precision(char *arg, t_flags *flags, size_t len)
{
	int	write_len;

	write_len = 0;
	if (flags->justify == '0')
	{
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		if (flags->len > flags->precision + len)
			write_len = ft_putjustify('0', flags->len - flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, arg, len);
	}
	else if (flags->justify == '-')
	{
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, arg, len);
		if (write_len < 0)
			return (-1);
		if (flags->len > flags->precision + len)
			write_len = ft_putjustify(' ', flags->precision - len);
	}
	else
	{
		if (flags->len > flags->precision + len)
			write_len = ft_putjustify(' ', flags->len - flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = ft_putjustify('0', flags->precision - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, arg, len);
	}
	if (write_len < 0)
		return (-1);
	if (flags->len)
		return (flags->len);
	return (len + flags->precision);
}

static int	ft_putunsign_justify(char *arg, t_flags *flags, size_t len)
{
	int	write_len;

	if (flags->justify == '0')
	{
		write_len = ft_putjustify('0', flags->len - len);
		if (write_len < 0)
			return (-1);
		write_len = write(1, arg, len);
	}
	else if (flags->justify == '-')
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
	return (flags->len);
}

int	ft_putunsign(unsigned int arg, t_flags *flags)
{
	char	*num;
	int		write_len;
	size_t	len;

	num = ft_uitoa(arg);
	if (!num)
		return (-1);
	len = ft_strlen(num);
	if (flags->precision >= len)
		write_len = ft_putunsign_precision(num, flags, len);
	else if (flags->len > len)
		write_len = ft_putunsign_justify(num, flags, len);
	else
		write_len = write(1, num, len);
	free(num);
	if (write_len < 0)
		return (-1);
	return (write_len);
}

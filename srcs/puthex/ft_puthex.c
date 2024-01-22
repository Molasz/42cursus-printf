/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:23:48 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/21 01:24:22 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_puthex_pre(int prefix, int lower)
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

static int	ft_puthex_normal(char *hex, int pre, int lower)
{
	if (ft_puthex_pre(pre, lower) < 0)
		return (1);
	if (write(1, hex, ft_strlen(hex)) < 0)
		return (1);
	return (0);
}

static int	ft_puthex_check(char *hex, t_flags *flags,
										int pre, int lower)
{
	int		write_len;
	size_t	len;

	len = ft_strlen(hex);
	if (flags->has_precision)
		write_len = ft_puthex_precision(hex, flags, pre, lower);
	else if (flags->len > len)
		write_len = ft_puthex_justify(hex, flags, pre, lower);
	else
	{
		if (ft_puthex_normal(hex, pre, lower) < 0)
			return (-1);
		if (pre)
			return (len + 2);
		return (len);
	}
	return (write_len);
}

int	ft_puthex(unsigned long arg, t_flags *flags, int lower, int p)
{
	char	*hex;
	int		write_len;
	int		prefix;
	size_t	len;

	hex = ft_strhex(arg, lower, flags);
	len = ft_strlen(hex);
	if (!hex)
		return (-1);
	prefix = (flags->prefix && arg) || p;
	if (flags->len > len && prefix)
		flags->len -= 2;
	write_len = ft_puthex_check(hex, flags, prefix, lower);
	free(hex);
	if (write_len < 0)
		return (-1);
	return (write_len);
}

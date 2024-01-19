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

static int	ft_puthex_precision(char *hex, int *flags, int pre, int lower)
{
	int	len;

	len = 0;
	if (flags[0] == 1)
	{
		if (pre)
			len = ft_puthex_pre(lower);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[4] - ft_strlen(hex), 2);
		if (len < 0)
			return (-1);
		len = write(1, hex, ft_strlen(hex));
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[3] - flags[4], 0);
	}
	else
	{
		len = ft_putjustify(flags[3] - flags[4], 0);
		if (len < 0)
			return (-1);
		if (pre)
			len = ft_puthex_pre(lower);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[4] - ft_strlen(hex), 2);
		if (len < 0)
			return (-1);
		len = write(1, hex, ft_strlen(hex));
	}
	return (len);
}

static int	ft_puthex_justify(char *hex, int *flags, int pre, int lower)
{
	int	len;

	len = 0;
	if (flags[0] == 2)
	{
		if (pre)
			len = ft_puthex_pre(lower);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[4] - ft_strlen(hex), 2);
		if (len < 0)
			return (-1);
		len = write(1, hex, ft_strlen(hex));
	}
	else if (flags[0] == 1)
	{
		if (pre)
			len = ft_puthex_pre(lower);
		if (len < 0)
			return (-1);
		len = write(1, hex, ft_strlen(hex));
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[4] - ft_strlen(hex), 0);
	}
	else
	{
		len = ft_putjustify(flags[4] - ft_strlen(hex), 0);
		if (len < 0)
			return (-1);
		if (pre)
			len = ft_puthex_pre(lower);
		if (len < 0)
			return (-1);
		len = write(1, hex, ft_strlen(hex));
	}
	return (len);
}

int	ft_puthex(unsigned long arg, int *flags, int lower, int p)
{
	char	*hex;
	int		len;

	len = 0;
	hex = ft_strhex(arg, lower);
	if (!hex)
		return (-1);
	if (flags[4] >= 0)
		len = ft_puthex_precision(hex, flags, (flags[2] && !arg) || p, lower);
	else if (flags[3])
		len = ft_puthex_justify(hex, flags, (flags[2] && !arg) || p, lower);
	else
	{
		if ((flags[2] && !arg) || p)
			len = ft_puthex_pre(lower);
		if (len < 0)
		{
			free(hex);
			return (-1);
		}
		len = write(1, hex, ft_strlen(hex));
	}
	if ((flags[2] && arg))
		len += 2;
	free(hex);
	if (len < 0)
		return (-1);
	return (len);
}

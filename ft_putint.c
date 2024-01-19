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

static int	ft_putint_precision(char *hex, int *flags, int zero, int lower)
{
	int	len;

	len = 0;
	if (flags[0] == 1)
	{
		if (flags[2] && !zero)
			len = ft_putint_pre(lower);
		if (len < 0)
			return (ft_free_all(hex));
		len = ft_putjustify(flags[4] - ft_strlen(hex), 2);
		if (len < 0)
			return (ft_free_all(hex));
		len = write(1, hex, ft_strlen(hex));
		if (len < 0)
			return (ft_free_all(hex));
		len = ft_putjustify(flags[3] - flags[4], 0);
	}
	else
	{
		len = ft_putjustify(flags[3] - flags[4], 0);
		if (len < 0)
			return (ft_free_all(hex));
		if (flags[2] && !zero)
			len = ft_putint_pre(lower);
		if (len < 0)
			return (ft_free_all(hex));
		len = ft_putjustify(flags[4] - ft_strlen(hex), 2);
		if (len < 0)
			return (ft_free_all(hex));
		len = write(1, hex, ft_strlen(hex));
	}
	return (len);
}

static int	ft_putint_justify(char *hex, int *flags, int zero, int lower)
{
	int	len;

	len = 0;
	if (flags[0] == 2)
	{
		if (flags[2] && !zero)
			len = ft_putint_pre(lower);
		if (len < 0)
			return (ft_free_all(hex));
		len = ft_putjustify(flags[4] - ft_strlen(hex), 2);
		if (len < 0)
			return (ft_free_all(hex));
		len = write(1, hex, ft_strlen(hex));
	}
	else if (flags[0] == 1)
	{
		if (flags[2] && !zero)
			len = ft_putint_pre(lower);
		if (len < 0)
			return (ft_free_all(hex));
		len = write(1, hex, ft_strlen(hex));
		if (len < 0)
			return (ft_free_all(hex));
		len = ft_putjustify(flags[4] - ft_strlen(hex), 0);
	}
	else
	{
		len = ft_putjustify(flags[4] - ft_strlen(hex), 0);
		if (len < 0)
			return (ft_free_all(hex));
		if (flags[2] && !zero)
			len = ft_putint_pre(lower);
		if (len < 0)
			return (ft_free_all(hex));
		len = write(1, hex, ft_strlen(hex));
	}
	return (len);
}

int	ft_putint(unsigned int arg, int *flags, int lower)
{
	char	*hex;
	int		len;

	len = 0;
	hex = ft_strhex(arg, lower);
	if (!hex)
		return (-1);
	if (flags[4])
		len = ft_putint_precision(hex, flags, arg == 0, lower);
	else if (flags[3])
		len = ft_putint_justify(hex, flags, arg == 0, lower);
	else
	{
		if (flags[2] && arg != 0)
			len = ft_putint_pre(lower);
		if (len < 0)
			return (ft_free_all(hex));
		len = write(1, hex, ft_strlen(hex));
	}
	if (len < 0)
		return (ft_free_all(hex));
	return (flags[4]);
}

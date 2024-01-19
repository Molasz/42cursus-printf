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

static int	ft_putint_precision(char *num, int *flags, int n)
{
	int	len;

	len = 0;
	if (flags[0] == 1)
	{
		if (flags[1] || n < 0)
			len = ft_putint_pre(n, flags[1]);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[4] - ft_strlen(num), 2);
		if (len < 0)
			return (-1);
		len = write(1, num, ft_strlen(num));
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[3] - flags[4], 0);
	}
	else
	{
		len = ft_putjustify(flags[3] - flags[4], 0);
		if (len < 0)
			return (-1);
		if (flags[1] || n < 0)
			len = ft_putint_pre(n, flags[1]);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[4] - ft_strlen(num), 2);
		if (len < 0)
			return (-1);
		len = write(1, num, ft_strlen(num));
	}
	if (len < 0)
		return (-1);
	if (flags[3])
		return (flags[3]);
	return (ft_strlen(num) + flags[4]);
}

static int	ft_putint_justify(char *num, int *flags, int n)
{
	int	len;

	len = 0;
	if (flags[0] == 2)
	{
		if (flags[1] || n < 0)
			len = ft_putint_pre(n, flags[1]);
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[3] - ft_strlen(num), 2);
		if (len < 0)
			return (-1);
		len = write(1, num, ft_strlen(num));
	}
	else if (flags[0] == 1)
	{
		if (flags[1] || n < 0)
			len = ft_putint_pre(n, flags[1]);
		if (len < 0)
			return (-1);
		len = write(1, num, ft_strlen(num));
		if (len < 0)
			return (-1);
		len = ft_putjustify(flags[3] - ft_strlen(num), 0);
	}
	else
	{
		if ((int)((size_t)flags[3] - ft_strlen(num)) > 0)
			len = ft_putjustify(flags[3] - ft_strlen(num), 0);
		if (len < 0)
			return (-1);
		if (flags[1] || n < 0)
			len = ft_putint_pre(n, flags[1]);
		if (len < 0)
			return (-1);
		len = write(1, num, ft_strlen(num));
	}
	if (len < 0)
			return (-1);
	if (ft_strlen(num) >= (size_t)flags[3])
		return (ft_strlen(num));
	return (flags[3]);
}

int	ft_putint(int arg, int *flags)
{
	char	*num;
	int		len;

	len = 0;
	num = ft_uitoa(ft_abs(arg));
	if (!num)
		return (-1);
	if (flags[3] && (flags[1] || arg < 0))
		flags[3]--;
	if (flags[4] >= 0)
		len = ft_putint_precision(num, flags, arg);
	else if (flags[3])
		len = ft_putint_justify(num, flags, arg);
	else
	{
		if (flags[1] || arg < 0)
			len = ft_putint_pre(arg, flags[1]);
		if (len < 0)
		{
			free(num);
			return (-1);
		}
		len = write(1, num, ft_strlen(num));
	}
	if (arg < 0 || flags[1])
		len++;
	free(num);
	if (len < 0)
		return (-1);
	return (len);
}

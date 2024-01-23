/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_justify.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:24:46 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/23 16:13:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_puthex_just_zero(char *hex, t_flags *flags, int pre, int lower)
{
	size_t	len;

	len = ft_strlen(hex);
	if (ft_puthex_pre(pre, lower) < 0)
		return (1);
	if (ft_putjustify('0', flags->len - len) < 0)
		return (1);
	if (write(1, hex, len) < 0)
		return (1);
	return (0);
}

static int	ft_puthex_just_left(char *hex, t_flags *flags, int pre, int lower)
{
	size_t	len;

	len = ft_strlen(hex);
	if (ft_puthex_pre(pre, lower) < 0)
		return (1);
	if (write(1, hex, len) < 0)
		return (1);
	if (ft_putjustify(' ', flags->len - len) < 0)
		return (1);
	return (0);
}

static int	ft_puthex_just_space(char *hex, t_flags *flags, int pre, int lower)
{
	size_t	len;

	len = ft_strlen(hex);
	if (ft_putjustify(' ', flags->len - len) < 0)
		return (1);
	if (ft_puthex_pre(pre, lower) < 0)
		return (1);
	if (write(1, hex, len) < 0)
		return (1);
	return (0);
}

int	ft_puthex_justify(char *hex, t_flags *flags, int pre, int lower)
{
	int		error;

	if (flags->justify == '0')
		error = ft_puthex_just_zero(hex, flags, pre, lower);
	else if (flags->justify == '-')
		error = ft_puthex_just_left(hex, flags, pre, lower);
	else
		error = ft_puthex_just_space(hex, flags, pre, lower);
	if (pre)
		flags->len += 2;
	if (error)
		return (-1);
	return (flags->len);
}

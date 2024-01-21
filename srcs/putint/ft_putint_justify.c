/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_justify.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:07:46 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/21 17:07:47 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_putint_just_zero(char *num, t_flags *flags, int n, size_t len)
{
	if (ft_putint_pre(n, flags->sign) < 0)
		return (1);
	if (ft_putjustify('0', flags->len - len) < 0)
		return (1);
	if (write(1, num, len) < 0)
		return (1);
	return (0);
}

int	ft_putint_just_left(char *num, t_flags *flags, int n, size_t len)
{
	if (ft_putint_pre(n, flags->sign) < 0)
		return (1);
	if (write(1, num, len) < 0)
		return (1);
	if (ft_putjustify(' ', flags->len - len) < 0)
		return (1);
	return (0);
}

int	ft_putint_justify(char *num, t_flags *flags, int n, size_t len)
{
	int	error;

	error = 0;
	if (flags->justify == '0')
		error = ft_putint_just_zero(num, flags, n, len);
	else if (flags->justify == '-')
		error = ft_putint_just_left(num, flags, n, len);
	else
	{
		if (ft_putjustify(' ', flags->len - len) < 0)
			return (-1);
		if (ft_putint_pre(n, flags->sign) < 0)
			return (-1);
		if (write(1, num, len) < 0)
			return (-1);
	}
	if (error)
		return (-1);
	if (flags->sign || n < 0)
		flags->len++;
	return (flags->len);
}

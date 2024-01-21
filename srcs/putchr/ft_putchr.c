/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:22:22 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/21 01:22:24 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_putchr_justify(char arg, t_flags *flags)
{
	if (flags->justify == '0')
	{
		if (ft_putjustify(' ', flags->len - 1) < 0)
			return (-1);
		if (write(1, &arg, 1) < 0)
			return (-1);
	}
	else if (flags->justify == '-')
	{
		if (write(1, &arg, 1) < 0)
			return (-1);
		if (ft_putjustify(' ', flags->len - 1) < 0)
			return (-1);
	}
	else
	{
		if (ft_putjustify(' ', flags->len - 1) < 0)
			return (-1);
		if (write(1, &arg, 1) < 0)
			return (-1);
	}
	return (flags->len);
}

int	ft_putchr(char arg, t_flags *flags)
{
	int	write_len;

	if (flags->len > 1)
		write_len = ft_putchr_justify(arg, flags);
	else
		write_len = write(1, &arg, 1);
	return (write_len);
}

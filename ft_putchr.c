/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:55:25 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 14:20:06 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char arg, t_flags *flags)
{
	int	write_len;

	write_len = 0;
	if (flags->len > 1)
	{
		if (flags->justify == '0')
		{
			write_len = ft_putjustify('0', flags->len - 1);
			if (write_len < 0)
				return (-1);
			write_len = write(1, &arg, 1);
		}
		else if (flags->justify == '-')
		{
			write_len = write(1, &arg, 1);
			if (write_len < 0)
				return (-1);
			write_len = ft_putjustify(' ', flags->len - 1);
		}
		else
		{
			write_len = ft_putjustify(' ', flags->len - 1);
			if (write_len < 0)
				return (-1);
			write_len = write(1, &arg, 1);
		}
		if (write_len < 0)
			return (-1);
		return (flags->len);
	}
	else
		return (write(1, &arg, 1));
}

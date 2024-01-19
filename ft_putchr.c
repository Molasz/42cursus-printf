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

int	ft_putchr(char arg, int *flags)
{
	int	len;

	len = 0;
	if (flags[3])
	{
		if (flags[0] == 2)
		{
			len = write(1, &arg, 1);
			if (len < 0)
				return (-1);
			len = ft_putjustify(flags[3] - 1, flags[0]);
		}
		else
		{
			len = ft_putjustify(flags[3] - 1, flags[0]);
			if (len < 0)
				return (-1);
			len = write(1, &arg, 1);
		}
		if (len < 0)
			return (-1);
		return (flags[3]);
	}
	else
		return (write(1, &arg, 1));
}

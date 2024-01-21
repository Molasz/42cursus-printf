/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:13:16 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/20 15:55:51 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_putjustify(char c, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
		i++;
	}
	return (size);
}

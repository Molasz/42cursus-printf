/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:13:16 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/19 18:50:44 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_putjustify(int size, int justify)
{
	char	c;
	int		i;

	i = 0;
	c = ' ';
	if (justify == 2)
		c = '0';
	while (i < size)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
		i++;
	}
	return (size);
}

int	ft_free_all(void *p)
{
	free(p);
	return (-1);
}

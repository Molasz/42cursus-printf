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

#include "../ft_printf.h"

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

static int	num_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_uitoa(unsigned int num)
{
	char			*str;
	int				str_size;
	int				str_count;

	str_size = 0;
	str_size += num_len(num);
	str = ft_calloc(sizeof (char), str_size + 1);
	if (!str)
		return (NULL);
	str_count = str_size - 1;
	while (str_count >= 0)
	{
		str[str_count] = (num % 10) + '0';
		num /= 10;
		str_count--;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:03:23 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/10 16:16:32 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

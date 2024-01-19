/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:13:16 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/18 15:49:31 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chrstr(char c)
{
	char	*s;

	s = ft_calloc(sizeof (char), 2);
	if (!s)
		return (NULL);
	s[0] = c;
	return (s);
}

char	*ft_chrstrjoin(char c, char *s)
{
	char	*res;
	int		len;

	len = ft_strlen(s);
	res = ft_calloc(sizeof(char), len + 2);
	if (!res)
	{
		free(s);
		return (NULL);
	}
	res[0] = c;
	ft_strlcpy(res + 1, s, len + 1);
	free(s);
	return (res);
}

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_putjustify(int size, int zero)
{
	char	c;
	int		i;

	i = 0;
	c = ' ';
	if (zero == 2)
		c = '0';
	while (i < size)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
		i++;
	}
	return (size);
}

int	ft_free(void *p)
{
	free(p);
	return (-1);
}
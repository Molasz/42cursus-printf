/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:44:38 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/18 12:00:44 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexlen(unsigned long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static char	*strhex(unsigned long n, char *base)
{
	char	*s;
	int		len;

	len = hexlen(n);
	s = ft_calloc(sizeof (char), len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (--len >= 0)
	{
		s[len] = base[n % 16];
		n /= 16;
	}
	return (s);
}

char	*ft_strhex(unsigned long nb, int lower, int prefix, int pointer)
{
	char	*res;
	char	*s;

	if (lower)
		s = strhex(nb, "0123456789abcdef");
	else
		s = strhex(nb, "0123456789ABCDEF");
	if (!s)
		return (NULL);
	if (prefix && (nb != 0 || pointer))
	{
		if (lower)
			res = ft_strjoin("0x", s);
		else
			res = ft_strjoin("0X", s);
		free(s);
		if (!res)
			return (NULL);
		return (res);
	}
	return (s);
}

char	*ft_strp(void *p)
{
	return (ft_strhex((unsigned long)p, 1, 1, 1));
}

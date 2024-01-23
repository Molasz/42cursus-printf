/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:44:38 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/23 16:13:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

static char	*strhex(unsigned long n, char *base, t_flags *flags)
{
	char	*s;
	int		len;

	len = hexlen(n);
	if (!n && flags->has_precision)
		len = 0;
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

char	*ft_strhex(unsigned long nb, int lower, t_flags *flags)
{
	char	*s;

	if (lower)
		s = strhex(nb, "0123456789abcdef", flags);
	else
		s = strhex(nb, "0123456789ABCDEF", flags);
	return (s);
}
